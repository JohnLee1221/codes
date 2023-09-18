#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const int& num_1, const int& num_2) {
  return num_1 > num_2;
}

class Compare {
 public:
  bool operator()(int a, int b) {
    return a < b;
  }
};

auto foo = [](int a, int b) {
              return a > b;
            };

int main() {
  std::vector<int> vec = {8,3,7,1,2,6,9,5,4};
  // sort(vec.begin(), vec.end(), compare);
  // sort(vec.begin(), vec.end(), Compare());
  sort(vec.begin(), vec.end(), foo);
  for (auto ele : vec) {
    std::cout << ele << std::endl;
  }

  return 0;
}