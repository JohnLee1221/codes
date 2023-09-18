#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> vec {"lalala", "hahaha", "hello world"};

  for (const std::string& elem : vec) {
    std::cout << elem << std::endl;
  }

  return 0;
}