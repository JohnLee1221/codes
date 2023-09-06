#include <iostream>
#include <memory>

void ShardPtr() {
  std::shared_ptr<int> auto_ptr;
  if (!auto_ptr) {
    std::cout << "no init" << std::endl;
  } else {
    std::cout << "init" << std::endl;
  }
}

int main() {
  ShardPtr();

  return 0;
}