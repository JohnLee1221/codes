#include <iostream>

long fbi_recursive(long n) {
  if (n <= 1) {
    return 1;
  }
  return fbi_recursive(n-1) + fbi_recursive(n-2);
}

long fbi_reasoning(long n) {
  long a = 1;
  long b = 1;
  if (n <= 1) {
    return 1;
  }
  for (int i = 2; i <= n; i++) {
    long temp = a + b;
    a = b;
    b = temp;
  }
  return b;
}

int main() {
  long result = fbi_reasoning(40);
  std::cout << result << std::endl;
  result = fbi_recursive(40);
  std::cout << result << std::endl;
  return 0;
}