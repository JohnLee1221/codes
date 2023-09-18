#include <iostream>

class PtrClass {
 public:
  void Init(const int& number) {
    ptr = &number;
    // ptr = new int(number);
  }

 public:
  const int *ptr;
};



int* Test() {
  int num = 100;
  int *a = &num;
  return a;
}

int main() {
  int *msg = Test();
  std::cout << "Hello" << std::endl;
  std::cout << *msg << std::endl;

  PtrClass ptr;
  int num = 100;
  // ptr.Init(100);
  ptr.Init(num);
  std::cout << "To print ptr value" << std::endl;
  std::cout << *(ptr.ptr) << std::endl;
  num++;
  std::cout << *(ptr.ptr) << std::endl;

  int *test_ptr1 = new int(100);
  int *test_ptr2 = test_ptr1;
  std::cout << test_ptr1 << std::endl;
  std::cout << *test_ptr1 << std::endl;
  std::cout << &test_ptr1 << std::endl;
  std::cout << test_ptr2 << std::endl;
  std::cout << *test_ptr2 << std::endl;
  std::cout << &test_ptr2 << std::endl;

std::cout << sizeof(test_ptr1) << std::endl;
std::cout << sizeof(int) << std::endl;
std::cout << sizeof(double) << std::endl;
std::cout << sizeof(float) << std::endl;
std::cout << sizeof(std::string) << std::endl;
std::cout << sizeof(long) << std::endl;





  return 0;
}