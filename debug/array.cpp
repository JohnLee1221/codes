#include <iostream>

void PrintArray(int *iterator, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    std::cout << *(iterator + i) << std::endl;
  }
}

int main() {
  int arr[] = {5, 4, 3, 4, 5};
  size_t arr_size = sizeof(arr) / sizeof(arr[1]);
  PrintArray(arr, arr_size);

  return 0;
}