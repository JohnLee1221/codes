#ifndef PLANNING_ROUTING_ROUTING_PATH_
#define PLANNING_ROUTING_ROUTING_PATH_

#include <vector>

#include "common/pnc_point.h"

constexpr auto kFileDir = "./data/routing_path.csv";

class RoutingPath {
 public:
  RoutingPath() = default;

  void CreatePath();

  std::vector<MapPoint> GetRoutingPathFromCSV(const std::string& file_path = kFileDir);

  void set_routing_path(const std::vector<MapPoint>& routing_path_points);

  const std::vector<MapPoint> get_routing_path() const;

 private:
  std::vector<std::string> StringParse(const std::string& line);

 private:
  std::vector<MapPoint> routing_path_points_;
};



#endif  // PLANNING_ROUTING_ROUTING_PATH_
