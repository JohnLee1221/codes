#ifndef PLANNING_REFERENCE_LINE_SMOOTHER_H_
#define PLANNING_REFERENCE_LINE_SMOOTHER_H_

#include "reference_line.h"
#include "config/reference_line_smoother_config.h"

class ReferenceLineSmoother {
 public:
  explicit ReferenceLineSmoother(const ReferenceLineSmootherConfig& config);

  void Smooth(const ReferenceLine& raw_reference_line,
              ReferenceLine& smooth_reference_line);

 private:
  bool DiscretePointSmooth(
      const std::vector<std::pair<double, double>>& raw_point2d, 
      std::vector<std::pair<double, double>> *ptr_smoothed_point2d);

 private:
  ReferenceLineSmootherConfig config_;

};

#endif  // PLANNING_REFERENCE_LINE_SMOOTHER_H_