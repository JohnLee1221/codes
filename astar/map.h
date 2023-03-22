#ifndef ASTAR_MAP_H_
#define ASTAR_MAP_H_

#include <iostream>
#include <fstream>
#include <vector>

constexpr auto MAP_PATH = "./map_data.txt";

namespace astar {

class Map {
 public:
  Map();
  Map(const std::string& str);
  std::vector<std::string> ParseMap();
 private:
  std::string str_;
  std::vector<int> temp_data_;
  std::vector<std::vector<int>> map_data_;
  std::ifstream file_;
};

} //  namespace astar

#endif // ASTAR_MAP_H_