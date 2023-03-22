#include <iostream>

using FuncPtr = bool (*)(int);
// using ObjPtr = bool (Person::*)(int);

bool foo(int num) {
  return num > 5;
}

class Person {
 public:
  bool test(int a) {
    return a == 8;
  }
};

int main() {
  FuncPtr  func_ptr = foo;
  std::cout << func_ptr(8) << std::endl;

  using ObjPtr = bool (Person::*)(int);
  ObjPtr obj_ptr = &Person::test;

  Person p;

  std::cout << (p.*obj_ptr)(1) << std::endl;

  return 0;
}