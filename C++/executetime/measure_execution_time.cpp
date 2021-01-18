#include <chrono>
#include <thread>
#include <iostream>

int main() {
  using clock = std::chrono::steady_clock;

  clock::time_point start = clock::now();
  for (int i = 0; i < 100; i++) {
    std::cout << i << std::endl;
    std::chrono::milliseconds sleepDuration(1000);
    std::this_thread::sleep_for(sleepDuration);
  }
  clock::time_point end = clock::now();

  clock::duration execution_time = end - start;

  //与秒的换算单位
  double ratio = (double)std::chrono::steady_clock::duration::period::num /
                 std::chrono::steady_clock::duration::period::den;

  std::cout << "run time : " << execution_time.count() * ratio << std::endl;
}
