#include <iostream>
#include <string>
#include <vector>
#include <sstream>

constexpr auto kSTR = "$GPYBM,SN10009927,085454.00,+31.284616159,+121.149198594,23.588,179.843,-0.818,0.024,-0.018,0.064,0.030,3463100.193,609429.443,,,1,4,42,200,,1.024,37,*56";

int main(int argc, char **argv) {
  std::istringstream ss(kSTR);
  std::vector<std::string> segment;
  std::string token;
  while (std::getline(ss, token, ',')) {
    segment.push_back(token);
  }
  double longitude = std::stod(segment[3]);
  double latitud = std::stold(segment[4]);
  std::cout << "logitdue is: " << longitude << std::endl;
  std::cout << "latitud is: " << latitud << std::endl;

  return 0;
}