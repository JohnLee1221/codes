#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Eigen>

int main() {
  Eigen::SparseMatrix<double> mat(5, 5);
  mat.setIdentity();


  std::cout << mat << std::endl;

  return 0;
}