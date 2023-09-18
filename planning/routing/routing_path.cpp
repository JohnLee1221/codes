#include "routing_path.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void RoutingPath::CreatePath() {
  routing_path_points_.clear();
  MapPoint point;
  point.x = 0;
  point.y = 0;
  routing_path_points_.push_back(point);
  double x = 0, y = 0;
  //第1段
  for (int i = 0; i < 60; i++) {
    x = x + 1;
    y = y + 0;
    point.x = x;
    point.y = y;
    routing_path_points_.push_back(point);
  }
  //第2段
  for (int i = 0; i < 20; i++) {
    x = x;
    y = y + 1;
    point.x = x;
    point.y = y;
    routing_path_points_.push_back(point);
  }
  //第3段
  for (int i = 0; i < 50; i++) {
    x = x + 1;
    y = y;
    point.x = x;
    point.y = y;
    routing_path_points_.push_back(point);
  }
  //第4段
  for (int i = 0; i < 20; i++) {
    x = x;
    y = y - 1;
    point.x = x;
    point.y = y;
    routing_path_points_.push_back(point);
  }
  //第5段
  for (int i = 0; i < 500; i++) {
    x = x + 1;
    y = y;
    point.x = x;
    point.y = y;
    routing_path_points_.push_back(point);
  }
}

std::vector<MapPoint> RoutingPath::GetRoutingPathFromCSV(const std::string& file_path) {
  std::ifstream file_in(file_path.c_str());
  if (!file_in.is_open()) {
    std::cout << "Can not open xxx file: " << file_path << std::endl;
    std::exit(1);
  }

  std::string line;
  MapPoint point;
  std::vector<MapPoint> path;
  // 跳过头行
  getline(file_in, line);

  while (true) {
    getline(file_in, line);
    if (line == "") {
      break;
    }
    auto tokens = StringParse(line);
    // 验证数据的完整性
    if (tokens.size() < 2) {
      std::cout << "parse line failed; the data dimension does not match."
          		<< line << std::endl;
      continue;
    }
    point.x = std::stod(tokens[0]);
    point.y = std::stod(tokens[1]);
    path.push_back(point);
  }

  file_in.close();
  return path;
}

void RoutingPath::set_routing_path(const std::vector<MapPoint>& routing_path_points) {
  routing_path_points_ = routing_path_points;
}

const std::vector<MapPoint> RoutingPath::get_routing_path() const {
  return routing_path_points_;
}

std::vector<std::string> RoutingPath::StringParse(const std::string& line) {
  std::istringstream ss(line);
  std::vector<std::string> segment;
  std::string token;
  while (std::getline(ss, token, ',')) {
    segment.push_back(token);
  }
  return segment;
}