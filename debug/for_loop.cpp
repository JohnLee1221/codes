#include <iostream>
#include <vector>

class Test {
 public:
  explicit Test(const std::string& str) {
    std::cout << str << "---" << std::endl;
  }
};

int main(int argc, char **argv) {
  Test("121");
  std::vector<std::string> vec {"Hello", "test", "lalala"};
  for (std::string elem : vec) {
    std::cout << elem << std::endl;
  }
//  for (auto elem : vec) {
//    std::cout << elem << std::endl;
//  }
  for (const Test& elem : vec) {


  }

  return 0;
}