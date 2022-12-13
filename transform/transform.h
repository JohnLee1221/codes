#ifndef TRANSFIRMS3D_TRANSFORMS_H_
#define TRANSFIRMS3D_TRANSFORMS_H_

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
using namespace Eigen;

class TransForms {
private:
public:
  //parse yaml file
  bool ParseYamlFile(const std::string& file_path);

  //Angle Degrees Part
  inline static double degrees(double angle) { return angle / 180 * M_PI; }

  inline static double angle(double degrees) { return degrees / M_PI * 180; }

  //EulerAngle Part
  static Matrix3d EulerAngle2Mat(double rx, double ry, double rz);

  static Matrix3d EulerAngle2Mat(Vector3d eular);

  static Quaterniond Euler2Quat(double rx, double ry, double rz);

  static Quaterniond EulerAngle2Quat(double rx, double ry, double rz);

  static Vector3d Mat2Euler(Matrix3d mat);

  static Matrix3d Euler2Mat(double rx, double ry, double rz);

  static Vector3d Mat2EulerAngle(Matrix3d mat);

  //Quaterniond Part
  static Matrix3d Quat2Mat(Quaterniond quat);

  static Vector3d Quat2Eular(Quaterniond quat);

  static Vector3d Quat2EularAngle(Quaterniond quat);

  static Quaterniond Mat2Quat(Matrix3d mat);



  TransForms(/* args */) = default;
  ~TransForms() = default;
};

#endif  //TRANSFIRMS3D_TRANSFORMS_H_