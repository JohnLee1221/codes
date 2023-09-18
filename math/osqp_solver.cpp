#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Eigen>
#include <OsqpEigen/OsqpEigen.h>

int main() {
    Eigen::SparseMatrix<double> hessian;
    hessian.resize(2,2);
    hessian.insert(0,0) = 1;
    hessian.insert(1,0) = -1;
    hessian.insert(0,1) = -1;
    hessian.insert(1,1) = 2;
    std::cout << "hessian:" << std::endl << hessian << std::endl;

    Eigen::VectorXd gradient;
    gradient.resize(2);
    gradient << -2, -6;
    
    std::cout << "gradient:" << std::endl << gradient << std::endl;

    Eigen::SparseMatrix<double> linearMatrix;
    linearMatrix.resize(3,2);
    linearMatrix.insert(0,0) = 1;
    linearMatrix.insert(0,1) = 1;
    linearMatrix.insert(1,0) = -1;
    linearMatrix.insert(1,1) = 2;
    linearMatrix.insert(2,0) = 2;
    linearMatrix.insert(2,1) = 1;
    std::cout << "linearMatrix:" << std::endl << linearMatrix << std::endl;

    Eigen::VectorXd lowerBound;
    Eigen::VectorXd upperBound;
    lowerBound.resize(3);
    lowerBound << -OsqpEigen::INFTY, -OsqpEigen::INFTY, -OsqpEigen::INFTY;
    std::cout << "lowerBound:" << std::endl << lowerBound << std::endl;

    upperBound.resize(3);
    upperBound << 2, 2, 3;
    std::cout << "upperBound:" << std::endl << upperBound << std::endl;

    int NumberOfVariables = 2; //A矩阵的列数
    int NumberOfConstraints = 3; //A矩阵的行数

    OsqpEigen::Solver solver;
        // set the initial data of the QP solver
    //矩阵A为m*n矩阵
    solver.settings()->setWarmStart(true);
    solver.data()->setNumberOfVariables(NumberOfVariables); //设置A矩阵的列数，即n
    solver.data()->setNumberOfConstraints(NumberOfConstraints); //设置A矩阵的行数，即m
    if(!solver.data()->setHessianMatrix(hessian)) return 1;//设置P矩阵
    if(!solver.data()->setGradient(gradient)) return 1; //设置q or f矩阵。当没有时设置为全0向量
    if(!solver.data()->setLinearConstraintsMatrix(linearMatrix)) return 1;//设置线性约束的A矩阵
    if(!solver.data()->setLowerBound(lowerBound)) return 1;//设置下边界
    if(!solver.data()->setUpperBound(upperBound)) return 1;//设置上边界


    return 0;
}
