#include <iostream>
#include <functional>

class Test {
 public:
  Test() = default;
  void foo(int num) {
    std::cout << "Hello" << "\t" << num << std::endl;
  }
};

void func(std::function<void()> f) {
  std::cout << "1" << std::endl;
  std::cout << "2" << std::endl;
  std::cout << "3" << std::endl;
  f();
  std::cout << "5" << std::endl;
  std::cout << "6" << std::endl;
}

int main() {
  Test test;
  // std::function<void(int)> callback = 
  std::function<void()> f = std::bind(&Test::foo,&test,std::placeholders::_1)(100);
  func(f);
  return 0;
}