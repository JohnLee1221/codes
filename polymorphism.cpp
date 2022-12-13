#include <iostream>

class Base {
 public:
  virtual void test() {
    std::cout << "base test" << std::endl;
  }
};

class Derived : public Base {
 public:
  virtual void test() {
    std::cout << "derived test" << std::endl;
  }
};

void func() {
  Base* ptr = new Derived();
  ptr->test();

  delete ptr;
}

int main() {
  func();
  return 0;
}