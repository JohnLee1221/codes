#ifndef PLANNING_CONFIG_REFERENCE_LINE_SMOOTHER_CONFIG_H_
#define PLANNING_CONFIG_REFERENCE_LINE_SMOOTHER_CONFIG_H_

struct ReferenceLineSmootherConfig {
  double weight_smooth = 70.0;
  double weight_path_length = 10.0;
  double weight_ref_deviation = 20.0;

  double x_lower_bound = -2.0;
  double x_upper_bound = 2.0;
  double y_lower_bound = -2.0;
  double y_upper_bound = 2.0;
};

#endif  // PLANNING_CONFIG_REFERENCE_LINE_SMOOTHER_CONFIG_H_
