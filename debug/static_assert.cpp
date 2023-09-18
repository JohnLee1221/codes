// assert.cpp
#include <iostream>
  
int main()
{
  static_assert(sizeof(int*) == 4, "错误, 不是32位平台...");
  // static_assert(sizeof(int*) == 8, "错误, 不是64位平台...");
  
  return 0;
}