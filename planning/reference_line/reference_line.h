#ifndef PLANNING_REFERENCE_LINE_REFERENCE_LINE_H_
#define PLANNING_REFERENCE_LINE_REFERENCE_LINE_H_

#include <vector>

#include "common/pnc_point.h"

class ReferenceLine {
 public:
  ReferenceLine() = default;
  ~ReferenceLine() = default;

  void set_reference_points(const ReferencePoints& reference_points) {
    reference_points_ = reference_points;
  }

  void set_match_point_index(const int& index) {
    match_point_index_ = index;
  }

  void set_host_match_point(const ReferencePoint& host_match_point) {
    host_match_point_ = host_match_point;
  }
  void set_host_project_point(const ReferencePoint& host_project_point) {
    host_project_point_ = host_project_point;
  }

  const ReferencePoints get_reference_points() const {
    return reference_points_;
  }

  const int get_match_point_index() const { return match_point_index_; }

  const ReferencePoint get_host_project_point() const {
    return host_project_point_;
  }

  const ReferencePoint get_host_match_point() const {
    return host_match_point_;
  }

 private:
  int match_point_index_{};                   // 自车匹配点索引
  ReferencePoints reference_points_;          // 参考点类
  ReferencePoint host_project_point_;
  ReferencePoint host_match_point_;
};

#endif  // PLANNING_REFERENCE_LINE_REFERENCE_LINE_H_
