#include "reference_line/reference_line_provider.h"

void ReferenceLineProvider::FindMatchAndProjectPoint(
    const ReferenceLine& frenet_path, const std::vector<MapPoint>& map_points,
    const int index_start_search, const int& increase_count_limit,
    std::vector<ReferencePoint>& match_points,
    std::vector<ReferencePoint>& project_points) {
  auto frenet_path_points = frenet_path.get_reference_points();
  int size = frenet_path_points.size();
  int increase_count = 0;
  match_points.resize(map_points.size());
  project_points.resize(map_points.size());
  for (int i = 0; i < map_points.size(); i++) {
    double min_distance = __DBL_MAX__;
    for (int j =index_start_search; j < size; j++) {
      double distance = pow(map_points[i].x - frenet_path_points[j].x, 2) +
                        pow(map_points[i].y - frenet_path_points[j].y, 2);


    }
  }
}