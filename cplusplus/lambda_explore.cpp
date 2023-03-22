#include <iostream>

class Test{
 public:
  void operator() () const {
    std::cout << "num_ value : " << num_ << std::endl;
  }
 private:
  int num_ = 100;
};

void test() {
  int a = 10;
  // auto f1 = [=]() {
  //   ++a;
  // };

  auto f2 = [=]()mutable {
    ++a;
  };
}

int main() {
  Test t;
  t();

  return 0;
}