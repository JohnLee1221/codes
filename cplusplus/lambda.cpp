#include <iostream>
#include <functional>

class Test {
 public:
  void Output(int num)
  {
    // []() {std::cout << num_ << std::endl; }();                      // error

    [=]() {
      std::cout << num << std::endl; 
      // std::cout << ++num << std::endl; 
    }();
    
    // [=]()mutable {
    //   std::cout << num << std::endl; 
    //   std::cout << ++num << std::endl; 
    // }();

    [&]() {
      std::cout << num << std::endl; 
      std::cout << ++num_ << std::endl; 
    }();

    [this]() {
      // std::cout << num << std::endl;
      std::cout << num_ << std::endl;
    }();

    [this, num]() {
      std::cout << num_ + num << std::endl;
    }();
  }
  void PrintNum() {
    std::cout << "num_ = " << num_ << std::endl;
  }
 private:
  int num_ = 1000;
};

int main() {

  int a = 10;
  auto f = [=]()-> int {
    return a;
  };
  std::cout << f() << std::endl;

  // Test test;
  // test.Output(100);
  // test.PrintNum();

  return 0;
}
