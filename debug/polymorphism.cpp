#include <iostream>

class Base {
 public:
  virtual void test() {
    std::cout << "base test" << std::endl;
  }
  virtual ~Base() {}
};

class Derived : public Base {
 public:
  void test() override {
    std::cout << "derived test" << std::endl;
  }
};

Base* foo(Base* base) {
  return base;
}

void func() {
  Base* ptr = new Derived();
  ptr->test();

  delete ptr;
}

int main() {
  func();
  Base* test = foo(new Derived());
  test->test();
  return 0;
}