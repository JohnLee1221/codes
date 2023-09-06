#include <iostream>
#include <vector>
#include <cmath>

const double NUM = std::sqrt(2);

struct Data {
  double x;
  double y;
};



std::vector<Data> Foo(std::vector<Data> vector) {
  std::vector<Data> tmp_vector;
  size_t size = vector.size();
  for (size_t i = 0; i < size - 1; ++i) {
    double delta_x = std::abs(vector[i].x - vector[i + 1].x);
    double delta_y = std::abs(vector[i].y - vector[i + 1].y);
    double delta = std::sqrt(delta_x * delta_x + delta_y * delta_y);
    if (delta == 0) {
      continue;;
    } else if (delta > NUM) {
    // if (delta > NUM) {
      int number = (delta + 0.05) / NUM;
      std::cout << number << std::endl;
      double precision_x = delta_x / number;
      double precision_y = delta_y / number;
      for (int j = 0; j < number; ++j) {
        Data tmp_data;
        tmp_data.x = vector[i].x + j * precision_x;
        tmp_data.y = vector[i].y + j * precision_y;
        tmp_vector.push_back(tmp_data);
      }
    } else {
      tmp_vector.push_back(vector[i]);
    }
  }
  tmp_vector.push_back(vector.back());
  return tmp_vector;
}

int main() {
  std::vector<Data> vec{{1, 1}, {2, 2}, {5, 5}, {5, 5}, {10, 10}, {11, 11}};
  auto result = Foo(vec);
  for (auto value : result) {
    std::cout << value.x << "\t" << value.y << std::endl;
  }
}