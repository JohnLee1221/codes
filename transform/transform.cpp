#include <iostream>
#include <yaml-cpp/yaml.h>
#include "transform.h"

bool TransForms::ParseYamlFile(const std::string& file_path) {
  YAML::Node tf_node;
  try {
    tf_node = YAML::LoadFile(file_path);
  } catch(...) {
    std::cout << "ERROR: extrinsic yaml file parse failed" << std::endl;
    return false;
  }
  tf_node["header"]["frame_id"].as<std::string>();
  tf_node["child_frame_id"].as<std::string>();
  //transform
  tf_node["transform"]["translation"]["x"].as<double>();
  tf_node["transform"]["translation"]["y"].as<double>();
  tf_node["transform"]["translation"]["z"].as<double>();
  //rotation
  tf_node["transform"]["rotation"]["x"].as<double>();
  tf_node["transform"]["rotation"]["y"].as<double>();
  tf_node["transform"]["rotation"]["z"].as<double>();
  tf_node["transform"]["rotation"]["w"].as<double>();
  std::cout << "parse yaml file success" << std::endl;
  return true;
}

Matrix3d TransForms::EulerAngle2Mat(double rx, double ry, double rz) {
  rx = degrees(rx);
  ry = degrees(ry);
  rz = degrees(rz);
  AngleAxisd rollAngle(AngleAxisd(rx, Vector3d::UnitX()));
  AngleAxisd pitchAngle(AngleAxisd(ry, Vector3d::UnitY()));
  AngleAxisd yawAngle(AngleAxisd(rz, Vector3d::UnitZ()));
  Matrix3d rotation_matrix;
  rotation_matrix = yawAngle * pitchAngle * rollAngle;
  return rotation_matrix;
}

Matrix3d TransForms::Euler2Mat(double rx, double ry, double rz) {
  AngleAxisd rollAngle(AngleAxisd(rx, Vector3d::UnitX()));
  AngleAxisd pitchAngle(AngleAxisd(ry, Vector3d::UnitY()));
  AngleAxisd yawAngle(AngleAxisd(rz, Vector3d::UnitZ()));
  Matrix3d rotation_matrix;
  rotation_matrix = yawAngle * pitchAngle * rollAngle;
  return rotation_matrix;
}

Quaterniond TransForms::Euler2Quat(double rx, double ry, double rz) {
  return Eigen::AngleAxisd(rx, ::Eigen::Vector3d::UnitX()) *
         Eigen::AngleAxisd(ry, ::Eigen::Vector3d::UnitY()) *
         Eigen::AngleAxisd(rz, ::Eigen::Vector3d::UnitZ());
}

Quaterniond TransForms::EulerAngle2Quat(double rx, double ry, double rz) {
  rx = degrees(rx);
  ry = degrees(ry);
  rz = degrees(rz);
  return Eigen::AngleAxisd(rx, ::Eigen::Vector3d::UnitX()) *
         Eigen::AngleAxisd(ry, ::Eigen::Vector3d::UnitY()) *
         Eigen::AngleAxisd(rz, ::Eigen::Vector3d::UnitZ());
}

Vector3d TransForms::Mat2Euler(Matrix3d mat) {
  return mat.eulerAngles(0, 1, 2);
}

Matrix3d TransForms::EulerAngle2Mat(Vector3d eular) {
  return EulerAngle2Mat(eular.x(), eular.y(), eular.z());
}

Vector3d TransForms::Mat2EulerAngle(Matrix3d mat) {
  Vector3d rot = mat.eulerAngles(2, 1, 0);
  rot = rot / M_PI * 180;
  return rot;
}

Matrix3d TransForms::Quat2Mat(Quaterniond quat) { return quat.matrix(); }


Vector3d TransForms::Quat2Eular(Quaterniond quat) {
  return Mat2Euler(quat.matrix());
}


Vector3d TransForms::Quat2EularAngle(Quaterniond quat) {
  return Mat2EulerAngle(quat.matrix());
}


Quaterniond TransForms::Mat2Quat(Matrix3d mat) { return Quaterniond(mat); }
