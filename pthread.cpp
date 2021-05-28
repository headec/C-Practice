#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex> 

using std::thread;
using std::vector;

void func1() {
  for (int i = 0; i < 10; i++) {
    std::cout << "������ 1 �۵���! \n";
  }
}

void func2() {
  for (int i = 0; i < 10; i++) {
    std::cout << "������ 2 �۵���! \n";
  }
}

void func3() {
  for (int i = 0; i < 10; i++) {
    std::cout << "������ 3 �۵���! \n";
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

  // �������� id �� ���Ѵ�.
  thread::id this_id = std::this_thread::get_id();
  printf("������ %x ���� %d ���� %d ���� ����� ��� : %d \n", this_id, *start,
         *(end - 1), sum);
}


//Part 3
void worker1(int& counter) {
  for (int i = 0; i < 10000; i++) {
    counter += 1;
  }
}

//Part 4
//�̷��� m.lock() �� m.unlock() ���̿� �� �����常�� �����ϰ� ������ �� �ִ� �ڵ� �κ��� �Ӱ� ����(critical section) �̶�� �θ��ϴ�.
//���� unlock �� ���� ������ �����(deadlock)�� �ɸ�.
void worker2(int& result, std::mutex& m) {
  for (int i = 0; i < 10000; i++) {
    m.lock();
    result += 1;
    m.unlock();
    //�Ǵ�
    // lock ���� �ÿ� m.lock() �� �����Ѵٰ� ���� �ȴ�.
    //std::lock_guard<std::mutex> lock(m);
    //result += 1;

    // scope �� ���� ������ lock �� �Ҹ�Ǹ鼭
    // m �� �˾Ƽ� unlock �Ѵ�.
  }
}

int main() {
  thread t1(func1);
  thread t2(func2);
  thread t3(func3);

//���������� join ��, �ش��ϴ� ��������� ������ �����ϸ� �����ϴ� �Լ� �Դϴ�. ���� t1.join() �� ��� t1 �� �����ϱ� �� ���� �������� �ʽ��ϴ�.
//   t1.join();
//   t2.join();
//   t3.join();

//detach �� �� �״��, �ش� �����带 ���� ��Ų ��, �ؾ������ �� �̶� �����Ͻø� �˴ϴ�. ��� ������� �˾Ƽ� ��׶��忡�� ���ư��� �˴ϴ�. �Ʒ� ������ ���� ���캸�ڽ��ϴ�.
  t1.detach();
  t2.detach();
  t3.detach();

  std::cout << "���� �Լ� ���� \n";

//Part 2

vector<int> data(10000);
  for (int i = 0; i < 10000; i++) {
    data[i] = i;
  }

  // �� �����忡�� ���� �κ� �յ��� �����ϴ� ����
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
  std::cout << "��ü �� : " << total << std::endl;

//Part 3
int counter = 0;

  vector<thread> workers1;
  for (int i = 0; i < 4; i++) {
    // ���۷����� �����Ϸ��� ref �Լ��� ���ξ� �Ѵ�
    workers1.push_back(thread(worker1 ,std::ref(counter)));
  }

  for (int i = 0; i < 4; i++) {
    workers1[i].join();
  }

  std::cout << "Counter ���� �� : " << counter << std::endl;

//Part 4
  counter = 0;
  std::mutex m;  // �츮�� mutex ��ü

  std::vector<std::thread> workers2;
  for (int i = 0; i < 4; i++) {
    workers2.push_back(std::thread(worker2, std::ref(counter), std::ref(m)));
  }

  for (int i = 0; i < 4; i++) {
    workers2[i].join();
  }

  std::cout << "Counter ���� �� : " << counter << std::endl;
}