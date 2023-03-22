#include "map.h"

int main() {
  astar::Map map;
  std::vector<std::vector<int>> data = map.ParseMap();
  for (auto element : data) {
    // std::cout << element.size() << std::endl;
    for (auto value : element) {
      std::cout << value << " ";
    }
    std::cout << "\n";
  }

  return 0;
}