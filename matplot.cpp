#include <cmath>
#include <vector>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main()
{
std::vector<double> x = {1, 2, 3, 4, 5};
std::vector<double> y = {2, 4, 6, 8, 10};

// 设置线宽
std::map<std::string, std::string> line_style;
line_style.insert(std::make_pair<std::string, std::string>("color", "green"));
line_style.insert(std::make_pair<std::string, std::string>("linewidth", "5"));
plt::plot(x, line_style);		// 绿色实线，线宽5

std::map<std::string, std::string> point_style;
point_style["color"] = "red";
point_style["marker"] = "o";
point_style["markersize"] = "5";
plt::plot(y, point_style);		// 红色点线，点大小为5
  plt::show();
  return 0;
}


