#ifndef PLANNING_REFERENCE_LINE_REFERENCE_LINE_PROVIDER_H_
#define PLANNING_REFERENCE_LINE_REFERENCE_LINE_PROVIDER_H_

#include <cmath>
#include <memory>

#include "reference_line/reference_line_smoother.h"

class ReferenceLineProvider {
 public:
  ReferenceLineProvider() = default;

  void Provide(const std::vector<MapPoint>& routing_path_points,
               const LocalizationInfo& localization_info,
               const ReferenceLine& pre_reference_line,
               ReferenceLine& reference_line);
  const ReferenceLine get_raw_reference_line() const;
  const ReferenceLine get_smoothed_reference_line() const;

  static void FindMatchAndProjectPoint(
      const ReferenceLine& frenet_path, const std::vector<MapPoint>& map_points,
      const int index_start_search, const int& increase_count_limit,
      std::vector<ReferencePoint>& match_points,
      std::vector<ReferencePoint>& project_points);

 private:
  void GetReferenceLine(const ReferenceLine& frenet_path,
                        const int& host_match_point_index,
                        ReferenceLine& reference_line);

  void RoutingPath2FrenetPath(const std::vector<MapPoint>& routing_path_points,
                              ReferenceLine *frenet_path);


 private:
  ReferenceLine frenet_path_;
  std::vector<MapPoint> pre_points_;
  bool is_first_run_ = false;
  ReferenceLine raw_reference_line_;
  ReferenceLine smoothed_reference_line_;
  ReferenceLine host_project_point_;
  ReferenceLine host_match_point_;
};

#endif  // PLANNING_REFERENCE_LINE_REFERENCE_LINE_PROVIDER_H_