#include "reference_line_smoother.h"
#include <OsqpEigen/OsqpEigen.h>
#include <eigen3/Eigen/Eigen>


ReferenceLineSmoother::ReferenceLineSmoother(
    const ReferenceLineSmootherConfig& config) : config_(config) {}

void ReferenceLineSmoother::Smooth(const ReferenceLine& raw_reference_line,
                                   ReferenceLine& smooth_reference_line) {

}



bool ReferenceLineSmoother::DiscretePointSmooth(
    const std::vector<std::pair<double, double>>& raw_point2d, 
    std::vector<std::pair<double, double>> *smoothed_point2d) {
  int n = raw_point2d.size();

  // 初始化A1, A2, A3, f, lb, ub矩阵
  // 平滑代价系数矩阵，x'A1'A1x, (n - 2)
  Eigen::SparseMatrix<double> A1(2 * n, 2 * n);
  // 路径长度代价矩阵，x'A2'A2x, (n - 1)
  Eigen::SparseMatrix<double> A2(2 * n, 2 * n);
  // 参考线偏离代价矩阵，x'A3'A3x
  Eigen::SparseMatrix<double> A3(2 * n, 2 * n);

  // H必须是稀疏矩阵
  Eigen::SparseMatrix<double> H(2 * n, 2 * n);
  Eigen::VectorXd f = Eigen::VectorXd::Zero(2 * n);
  Eigen::SparseMatrix<double> A(2 * n, 2 * n);
  Eigen::VectorXd lb = Eigen::VectorXd::Zero(2 * n);
  Eigen::VectorXd ub = Eigen::VectorXd::Zero(2 * n);
  Eigen::VectorXd qp_solution = Eigen::VectorXd::Zero(2 * n);

  A.setIdentity();

  // assign f, lb, ub;
  for (int i = 0; i < n; i++) {
    f(2 * i) = raw_point2d[i].first;
    f(2 * i + 1) = raw_point2d[i].second;

    lb(2 * i) = f(2 * i) + config_.x_lower_bound;
    lb(2 * i + 1) = f(2 * i + 1) + config_.y_lower_bound;

    ub(2 * i) = f(2 * i) + config_.x_upper_bound;
    ub(2 * i + 1) = f(2 * i + 1) + config_.y_upper_bound;
  }

  // assign A1
  for (int j = 0; j < n - 2; j++) {
    A1.insert(2 * j, 2 * j) = 1;
    A1.insert(2 * j, 2 * j + 2) = -2;
    A1.insert(2 * j, 2 * j + 4) = 1;
    A1.insert(2 * j + 1, 2 * j + 1) = 1;
    A1.insert(2 * j + 1, 2 * j + 3) = -2;
    A1.insert(2 * j + 1, 2 * j + 5) = 1;
  }

  // assign A2
  for (int k = 0; k < n - 1; k++) {
    A2.insert(2 * k, 2 * k) = 1;
    A2.insert(2 * k, 2 * k + 2) = -1;
    A2.insert(2 * k + 1, 2 * k + 1) = 1;
    A2.insert(2 * k + 1, 2 * k + 3) = 1;
  }

  // assign A3
  A3.setIdentity();

  H = 2 * (config_.weight_smooth * A1.transpose() * A1 + 
           config_.weight_path_length * A2.transpose() * A2 +
           config_.weight_ref_deviation * A3);

  f = -2 * config_.weight_ref_deviation * f;

  OsqpEigen::Solver solver;
  solver.settings()->setWarmStart(true);
  solver.data()->setNumberOfVariables(2 * n);
  solver.data()->setNumberOfConstraints(2 * n);
  solver.data()->setHessianMatrix(H);
  solver.data()->setGradient(f);
  solver.data()->setLinearConstraintsMatrix(A);
  solver.data()->setLowerBound(lb);
  solver.data()->setUpperBound(ub);
  
  if (!solver.initSolver()) {
    return 0;
  }
  if (!solver.solve()) {
    return 0;
  }
  qp_solution = solver.getSolution();

  smoothed_point2d->resize(n);
  for (int i = 0; i < n; i++) {
    smoothed_point2d->at(i).first = qp_solution(2 * i);
    smoothed_point2d->at(i).second = qp_solution(2 * i + 1);
  }
}
