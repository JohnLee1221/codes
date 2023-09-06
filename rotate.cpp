#include <algorithm>
#include <vector>
#include <iostream>

// int main() {
//     std::vector<int> numbers = {1, 2, 3, 4, 5};

//     // 将范围内的元素向左旋转一位
//     std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());

//     // 输出旋转后的结果
//     for (int num : numbers) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

    // size_t i;
    // for (i = 1; i < (numbers.size() -1) / 2 + 1; ++i) {
    //   std::rotate(numbers.begin() + i, numbers.begin() + i + 1, numbers.end());
    // }
    // std::reverse(numbers.begin() + i + 1, numbers.end());
    // if (numbers.size() % 2 == 1) {
    //   std::rotate(numbers.begin() + i, numbers.begin() + i + 1, numbers.end());
    // }

  std::vector<int> result;
    size_t n = numbers.size() / 2;
    std::cout << n << std::endl;
    
    for (size_t i = 0; i < n; ++i) {
      result.push_back(numbers[i]);
      result.push_back(numbers[i + n]);
    }
    if (numbers.size() % 2 == 1) {
      std::cout << "test" << std::endl;
      result.push_back(numbers.back());
    }
  
  // 输出结果
  for (const auto& num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
