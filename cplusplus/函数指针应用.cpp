#include <iostream>
#include <vector>
#include <algorithm>

bool max2min(int a, int b) {
  return a > b ? true : false;
}

bool min2max(int a, int b) {
  return a < b ? true : false;
}

void test01() {
  std::vector<int> v = {1,6,4,3,7,5,9,0,2,8};
  // std::sort(v.begin(), v.end(), max2min);
  std::sort(v.begin(), v.end(), min2max);

  for (auto value : v) {
    std::cout << value << " ";
  }
  std::cout << "\n";
}

int main() {
  test01();

  return 0;
}
