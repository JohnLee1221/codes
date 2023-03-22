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
  int a = 100;
  int *ptr = &a;

  test(*ptr);

  return 0;
}