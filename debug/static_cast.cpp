#include <iostream>
#include <glog/logging.h>

int main() {
  int a = 100;
  double b = static_cast<double>(a);
  // double b = static_cast<double>(a);
  std::cout << typeid(static_cast<double>(a)).name() << std::endl;

  return 0;
}