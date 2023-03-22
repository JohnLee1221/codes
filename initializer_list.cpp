#include <iostream>

void print(std::initializer_list<std::string> msg) {
  for (auto iter = msg.begin(); iter != msg.end(); iter += 2) {
    std::cout << *iter << std::endl;
  }
  std::cout << "******************************" << std::endl;
  for (auto iter = msg.begin()+1; iter != msg.end()+1; iter += 2) {
    std::cout << *iter << std::endl;
  }
}

int main() {
  std::initializer_list<std::string> init_list = {"0", "1" ,"2", "3", "4", "5", "6", "7"};
  print(init_list);
  
  return 0;
}