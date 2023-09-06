#include <iostream>
#include <cmath>

struct Point {
  double x;
  double y;
};

double GetOrientation(const Point& p1, const Point& p2) {
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return std::atan2(dy, dx);
}

int main() {
  Point p1 = {0.0, 0.0};
  Point p2 = {1.0, 1.0};
  
  double orientation = GetOrientation(p1, p2);
  
  // 将弧度转换为度数
  double degrees = orientation * 180.0 / M_PI;

  std::cout << orientation << std::endl;
  std::cout << degrees << std::endl;
  
  return 0;
}
