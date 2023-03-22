#include <iostream>
#include <functional>

void func(std::function<void(int)> f) {
  f(10);
}

int main() {
  int a = 100;
  int b = 20;
  auto test = [=](int num) {
              std::cout << a << std::endl;
              std::cout << b << std::endl;
              std::cout << num << std::endl;
            };
  auto foo = std::bind([=](int num) {
                std::cout << a << std::endl;
                std::cout << b << std::endl;
                std::cout << num << std::endl;
              },std::placeholders::_1);
  func(foo);

  return 0;
}