#include <iostream>
#include <vector>
#include <functional>

namespace Work {

namespace A {
  int a = 1;
  int b = 1000;

namespace B {
  void func() {
    std::cout << "test" << std::endl;
  }
} // namespace B

namespace C {
  void test() {
    std::cout << Work::A::a << std::endl;
    B::func();
  }
} // namesapce C

} // namespace A

}

int main() {
  // using Work::A::a;
  // using Work::A::b;
  using namespace Work::A;

  int b = 100;

  // ...

  std::cout << Work::A::a << std::endl;
  // std::cout << Work::A::b << std::endl;
  std::cout << b << std::endl;

  return 0;
}