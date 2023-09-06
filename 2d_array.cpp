#include <iostream>

int main() {
  int array[2][3] = {{1, 2, 3}, {555, 666, 777}};

  int **p = new int *[3];
  int (*ptr)[3] = array;

  int size1 = sizeof(array) / sizeof(array[0]);
  int size2 = sizeof(array[0]) / sizeof(int);
  std::cout << sizeof(array) << std::endl;

  for (int i = 0; i < size1; i++) {
    for (int j = 0; j < size2; j++) {
      std::cout << *(*(ptr + i) + j) << std::endl;
    }
  }
  return 0;
}