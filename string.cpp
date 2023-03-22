#include <iostream>

void test(const std::string& s) {
  std::cout << s << std::endl;
}

int main() {
  std::string str = "Hello";
  const char* c = str.c_str();
  test(c);

  return 0;
}