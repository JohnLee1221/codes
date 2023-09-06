#include <iostream>
#include <memory>

class Test {
 public:
  Test(const std::string& str = "test") : str_(new std::string(str)) {
    std::cout << *str_ << std::endl;
  }

  // Test(const Test& test) {
  //   std::string *tmp_str = new std::string(*test.str_);
  //   this->str_ = tmp_str;
  // }
 private:
  std::string *str_ = nullptr;

 public:
  void Deleter() {
    std::cout << *str_ << "\t";
    delete str_;
    std::cout << "costum distructor function" << std::endl;
  }

 public:
  ~Test() {
    std::cout << *str_ << "\t";
    delete str_;
    std::cout << "distructor function" << std::endl;
  }
};

void DeleterFunc(Test* t) {
  t->Deleter();
}

namespace {
int Max(int a, int b) {
  return a > b ? a : b;
}

void func(int (*f)(int, int)) {
  std::cout << "-----Start-----" << std::endl;
  int max_num = f(10, 20);
  std::cout << max_num << std::endl;
  std::cout << "-----end-----" << std::endl;
}
}

void (*f1)(Test*) = DeleterFunc;
 
typedef void (*PtrType)(Test*);
PtrType f2 = DeleterFunc;
using PtrAlias = void (*)(Test*);
PtrAlias f3 = DeleterFunc;


int main(int argc, char **argv) {
  func(::Max);
  // Test test1;
  // Test test2(test1);
  std::cout << "----------------------" << std::endl;
  std::shared_ptr<Test> test_ptr1 = std::make_shared<Test>("test_ptr1");
  // std::shared_ptr<Test> test_ptr2(test_ptr1);
  std::cout << "----------------------" << std::endl;
  std::shared_ptr<Test> test_ptr3(new Test("test_ptr3"), 
      [](Test* t) { t->Deleter(); });
  std::shared_ptr<Test> test_ptr4(new Test("test_ptr4"), f3);

  return 0;
}