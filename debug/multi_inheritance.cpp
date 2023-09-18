#include <iostream>
#include <memory>

class Person1 {
 public:
  virtual void test1() = 0;
};

class Person2 {
 public:
  virtual void test2() = 0;
};

class Test : public Person1, public Person2 {
 public:
  void test1() {
    std::cout << "Inheritance from Person1" << std::endl;
  }

  void test2() {
    std::cout << "Inheritance from Person2" << std::endl;
  }
};

int main() {
  std::shared_ptr<Person1> ptr1 = std::make_shared<Test>();
  ptr1->test1();
  // ptr1->test2();

  std::shared_ptr<Person2> ptr2 = std::make_shared<Test>();
  ptr2->test2();

  return 0;
}