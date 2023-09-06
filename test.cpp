#include <iostream>
#include <vector>
#include <cassert>
#include <memory>

void test(const int &a) {
  int b = 200;
  const int* ptr = &a;
  ptr = &b;
  std::cout << *ptr << std::endl;
}

int main() {
  std::cout << __cplusplus << std::endl;
}