#include <iostream>

const int& test(const int& num) {
  return num;
}

int main() {
  const int a = 10;
  auto b = test(a);
  ++a;
  b++;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  return 0;
}