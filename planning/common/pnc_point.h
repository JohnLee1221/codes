#ifndef PLANNING_COMMON_PNC_POINT_H_
#define PLANNING_COMMON_PNC_POINT_H_

#include <vector>

using ReferencePoints = std::vector<ReferencePoint>;

struct MapPoint {
  double x{};
  double y{};
};

struct ReferencePoint : public MapPoint {
  double index{};
  double heading{};
  double kappa{};     // curvature
  double dkappa{};    // derivative of curvature
};

struct TrajectoryPoint : public ReferencePoint {
  double v{};       // velocity
  double vx{};
  double vy{};
  double a{};       // accelerated velocity
  double ax{};
  double ay{};
  double t{};
};

struct ObstacleInfo : public TrajectoryPoint {
  int id{};
  double init_x{};
  double init_y{};
  double init_heading{};
  double v{};
  double heading{};
};

struct LocalizationInfo : public TrajectoryPoint {
};

struct SLPoint {
  int index{};
  double s{};         // path length
  double ds_dt{};     // velocity
  double dds_dt{};    // accelerated velocity
  double l{};         // lateral position
  double dl_dt{};     // lateral velocity
  double ddl_dt{};    // lateral accelerated velocity
  double dddl_dt{};
  double dl_ds{};
  double ddl_ds{};
  double dddl_ds{};

  // the cost from the start point to the current point
  double cost2start{};
  // the row number of the column preceding the minimum cost
  int pre_mincost_row{};
};

struct STPoint {
  double t{};
  double s{};
  double ds_dt{};
  double dds_dt{};

  double cost2start{};
  double pre_mincost_row{};
};

struct STLine {
  STPoint left_point{};
  STPoint right_point{};
};

#endif  // PLANNING_COMMON_PNC_POINT_H_