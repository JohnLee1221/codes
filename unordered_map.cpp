#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
  std::vector<int> list;
  list.push_back(5);
  list.push_back(14);
  list.push_back(34);
  list.push_back(22);
  list.push_back(39);
  list.push_back(5);

  std::unordered_map<int, int> map;
  for (int i = 0; i < list.size(); i++) {
    map[i] = list[i];
  }
  std::cout << map[0] << std::endl;
  std::cout << map[1] << std::endl;

  return 0;
}