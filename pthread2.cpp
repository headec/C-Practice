//데드락이 생기는 경우:
#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
#include <thread>

void worker1(std::mutex& m1, std::mutex& m2) {
  for (int i = 0; i < 10000; i++) {
    std::lock_guard<std::mutex> lock1(m1);
    std::lock_guard<std::mutex> lock2(m2);
    // Do something
  }
}

void worker2(std::mutex& m1, std::mutex& m2) {
  for (int i = 0; i < 10000; i++) {
    std::lock_guard<std::mutex> lock2(m2);
    std::lock_guard<std::mutex> lock1(m1);
    // Do something
  }
}

int main() {
  int counter = 0;
  std::mutex m1, m2;  // 우리의 mutex 객체

  std::thread t1(worker1, std::ref(m1), std::ref(m2));
  std::thread t2(worker2, std::ref(m1), std::ref(m2));

  t1.join();
  t2.join();

  std::cout << "끝!" << std::endl;
}