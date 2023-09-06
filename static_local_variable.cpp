#include <iostream>

class Test {
 public:
  Test() {
    std::cout << "Test class constructor" << std::endl;
  }
  ~Test() {
    std::cout << "Test class distructor" << std::endl;
  }
};

static Test test;

void Foo() {
  static Test t;
}

void Foo2() {
  std::cout << "print Foo2 function" << std::endl;
}

int main() {
  std::cout << __LINE__ << std::endl;
  // Foo();
  std::cout << __LINE__ << std::endl;
  Foo2();
  std::cout << __LINE__ << std::endl;

  return 0;
}