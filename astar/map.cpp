#include "map.h"
#include <cassert>
#include <fstream>
#include <sstream>
#include <vector>

namespace astar {

Map::Map() : Map::Map(MAP_PATH) {
  std::cout << "Open default map" << std::endl;
}
Map::Map(const std::string& map_path) : file_(map_path) {
  if (file_.is_open()) {
    std::cout << "Open map Sucess" << std::endl;
  } else {
    std::cout << "Open map False" << std::endl;
    assert(false);
  }
}
std::vector<std::string> Map::ParseMap() {
  while (std::getline(file_, str_)) {
    std::istringstream input(str_);
    int temp;
    while (input >> temp) {
      temp_data_.push_back(temp);
    }
    map_data_.push_back(temp_data_);

  }
  return map_data_;
}

}  // namespace astar