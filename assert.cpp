#include <iostream>
#include <cassert>

int foo(int num) {
  assert(num);
  return 100 / num;
}

int main() {
  foo(10);
  foo(0);   // 不能等于0, 否则程序中断

  return 0;
}