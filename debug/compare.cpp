#include <iostream>

constexpr int kMax = 10;

int test(const int& value) {
  return (value > kMax) ? kMax : (value < -kMax) ? -kMax : value;
}

int main() {
  int num_1 = test(5);
  std::cout << num_1 << std::endl;
  int num_2 = test(20);
  std::cout << num_2 << std::endl;
  int num_3 = test(-20);
  std::cout << num_3 << std::endl;

  return 0;
}