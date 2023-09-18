#include <iostream>

class Base {
 public:
  void Test() {
    std::cout << "test" << std::endl;
  }
};

int main() {
  Base *b;
  b->Test();

  return 0;
}