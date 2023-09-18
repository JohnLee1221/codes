#include <iostream>

class Test {
 public:
  Test() = default;
  void print() {
    std::cout << "Hello World" << std::endl;
  }
  Test(const Test& t) = delete;
};

int main() {
  Test t;
  t.print();
  // Test test1(t);
  // test1.print();
  // auto test2 = t;    //Test(const Test& t) = delete;
  // test2.print();
  return 0;
}