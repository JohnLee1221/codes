#include <iostream>
#include <stdlib.h>

int main() {
  for (int i = 0; i < 10; i++) {
    int random_num = rand() % 50 ;
    std::cout << random_num << std::endl;
  }

  return 0;
}