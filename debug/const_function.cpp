#include <iostream>

class MyClass {
 public:
  MyClass(const int& x) : x_(x) {}
  int x() const {
    return x_;
  }

  void Print() {
    std::cout << "x_ value is: " << x_ << std::endl;
  }

 private:
  int x_;
};

void Test(const MyClass my_class) {
  std::cout << my_class.x() << std::endl;
  my_class.Print();
}

int main() {
  MyClass c(100);
  // std::cout << c.x() << std::endl;
  // c.Print();

  return 0;
}