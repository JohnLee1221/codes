#include <iostream>

void temp(int num, std::string str) {
  std::cout << num << "\t" << str << std::endl;
}

void(*f)(int, std::string) = temp;

using  Fptr1 = void(*)(int, std::string);

typedef void(*Fptr2)(int, std::string);

void test01(void(*F)(int, std::string)) {
  F(111, "function pointer");
}

void test02(Fptr1 fptr) {
  fptr(222, "function pointer from using");
}

void test03(Fptr2 fptr) {
  fptr(333, "function pointer from typedef");
}

int main() {
  test01(f);

  Fptr1 ptr1 = temp;
  Fptr2 ptr2 = temp;
  test02(ptr1);
  test03(ptr2);

  return 0;
}