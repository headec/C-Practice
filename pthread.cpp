#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex> 

using std::thread;
using std::vector;

void func1() {
  for (int i = 0; i < 10; i++) {
    std::cout << "쓰레드 1 작동중! \n";
  }
}

void func2() {
  for (int i = 0; i < 10; i++) {
    std::cout << "쓰레드 2 작동중! \n";
  }
}

void func3() {
  for (int i = 0; i < 10; i++) {
    std::cout << "쓰레드 3 작동중! \n";
  }
}

//Part 2
void worker(vector<int>::iterator start, vector<int>::iterator end,
            int* result) {
  int sum = 0;
  for (auto itr = start; itr < end; ++itr) {
    sum += *itr;
  }
  *result = sum;

  // 쓰레드의 id 를 구한다.
  thread::id this_id = std::this_thread::get_id();
  printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start,
         *(end - 1), sum);
}


//Part 3
void worker1(int& counter) {
  for (int i = 0; i < 10000; i++) {
    counter += 1;
  }
}

//Part 4
//이렇게 m.lock() 과 m.unlock() 사이에 한 쓰레드만이 유일하게 실행할 수 있는 코드 부분을 임계 영역(critical section) 이라고 부릅니다.
//만약 unlock 을 하지 않으면 데드락(deadlock)이 걸림.
void worker2(int& result, std::mutex& m) {
  for (int i = 0; i < 10000; i++) {
    m.lock();
    result += 1;
    m.unlock();
    //또는
    // lock 생성 시에 m.lock() 을 실행한다고 보면 된다.
    //std::lock_guard<std::mutex> lock(m);
    //result += 1;

    // scope 를 빠져 나가면 lock 이 소멸되면서
    // m 을 알아서 unlock 한다.
  }
}

int main() {
  thread t1(func1);
  thread t2(func2);
  thread t3(func3);

//마지막으로 join 은, 해당하는 쓰레드들이 실행을 종료하면 리턴하는 함수 입니다. 따라서 t1.join() 의 경우 t1 이 종료하기 전 까지 리턴하지 않습니다.
//   t1.join();
//   t2.join();
//   t3.join();

//detach 는 말 그대로, 해당 쓰레드를 실행 시킨 후, 잊어버리는 것 이라 생각하시면 됩니다. 대신 쓰레드는 알아서 백그라운드에서 돌아가게 됩니다. 아래 예제를 통해 살펴보겠습니다.
  t1.detach();
  t2.detach();
  t3.detach();

  std::cout << "메인 함수 종료 \n";

//Part 2

vector<int> data(10000);
  for (int i = 0; i < 10000; i++) {
    data[i] = i;
  }

  // 각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
  vector<int> partial_sums(4);

  vector<thread> workers;
  for (int i = 0; i < 4; i++) {
    workers.push_back(thread(worker, data.begin() + i * 2500,
                             data.begin() + (i + 1) * 2500, &partial_sums[i]));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  int total = 0;
  for (int i = 0; i < 4; i++) {
    total += partial_sums[i];
  }
  std::cout << "전체 합 : " << total << std::endl;

//Part 3
int counter = 0;

  vector<thread> workers1;
  for (int i = 0; i < 4; i++) {
    // 레퍼런스로 전달하려면 ref 함수로 감싸야 한다
    workers1.push_back(thread(worker1 ,std::ref(counter)));
  }

  for (int i = 0; i < 4; i++) {
    workers1[i].join();
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;

//Part 4
  counter = 0;
  std::mutex m;  // 우리의 mutex 객체

  std::vector<std::thread> workers2;
  for (int i = 0; i < 4; i++) {
    workers2.push_back(std::thread(worker2, std::ref(counter), std::ref(m)));
  }

  for (int i = 0; i < 4; i++) {
    workers2[i].join();
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;
}