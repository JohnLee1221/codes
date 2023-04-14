#include <iostream>
#include <cassert>

class Test {
 public:
  Test() = default;

  int *ptr = new int(10);
  ~Test() {
    delete ptr;
    std::cout << "distructor function" << std::endl;
  }
};

int main() {
  Test t;
  assert(false);
  return 0;
}