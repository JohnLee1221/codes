#include <iostream>
#include <memory>

class Base {
 public:
  virtual void foo() = 0;
  int a = 1111;
};

class Devide : public Base {
 public:
  int num = 100;
  void foo() override {
    std::cout << "test" << std::endl;
  }
};

int main(int argc, char **argv) {
  std::shared_ptr<Base> ptr = std::make_shared<Devide>();
  auto sum_ptr = std::dynamic_pointer_cast<Devide>(ptr);  //向下转型
  ptr->foo();
  std::cout << ptr->a << std::endl;
  if (sum_ptr) {
    std::cout << sum_ptr->num << std::endl;
  }

  return 0;
}