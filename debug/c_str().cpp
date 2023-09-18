#include <iostream>

void func() {
  std::string str = "Hello";
  const char* ptr = str.c_str();
  std::string test = ptr;
  std::cout << *ptr << std::endl;

}

int main() {
  func();
  return 0;
}