#include <iostream>
#include <vector>

int main() {
  std::vector<int> arr{1, 2, 4, 5, 7, 11, 57, 68, 99, 104};

  int target = 68;

  int size = arr.size();

  int right = size;
  int left = -1;
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    if (arr[mid] < target) {
      left = mid;
    } else if (arr[mid] > target) {
      right = mid;
    } else {
      std::cout << arr[mid] << std::endl;
      break;
    }
  }

  std::cout << "can not search the target number: " << target << std::endl;
  return 0;
}