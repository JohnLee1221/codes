#include <iostream>
#include <vector>

int main() {
  int arr[] = {1,2,3,4,5,6,7};
  std::string str = "hello";
  std::vector<int> v = {1,2,3,4,5,6};

  std::cout << str.size() << std::endl;
  std::cout << str.length() << std::endl;

  std::cout << v.size() << std::endl;

  std::cout << *arr << std::endl;
  
  std::cout << sizeof(arr) / sizeof(*arr) << std::endl;

  return 0;
}