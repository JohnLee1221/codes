#include <iostream>
#include <typeinfo>
#include <vector>

int main() {
  #if 0
  std::vector<int> v;
  v.reserve(100);
  std::cout << v.size() << std::endl;
  for (int i = 0; i < 10; i++) {
    // v[i] = i;
    v.push_back(i);
    std::cout << v[i] << std::endl;
  }
  std::cout << v[5] << std::endl;
  std::cout << v.size() << std::endl;
  #endif

  std::vector<std::vector<int>> v;
  decltype(1) a;
  a = 100;
  std::cout << typeid(v).name() << std::endl;
  std::cout << typeid(a).name() << std::endl;

  return 0;
}