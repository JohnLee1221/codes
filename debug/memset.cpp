#include <iostream>
#include <cstring>

struct Test {
  int a;
  int b;
};

int main() {
  Test t;
  std::string str1;
  memset(&str1, 97, sizeof(str1));
  std::cout << str1 << std::endl;

  return 0;
}