#include <iostream>

class MyClass {
 public:
  MyClass(const int& value) : value_(value), value_ptr_(new int(value)){}

  const int& getValue() { return value_; }
  const int* getValuePtr() { return value_ptr_; }

 private:
  int value_{};
  int *value_ptr_{};
};

class Test {
 public:
   int value() const { return value_; }

 private:
  int value_ = 100;
};

void GetMsg(const Test& m) {
    int num = m.value();
    std::cout << num << std::endl;
}

int main() {
  MyClass m(1);
  
  const int& a = m.getValue();

  int number = 666;
  const int* b = m.getValuePtr();
  b = &number;
  std::cout << *m.getValuePtr() << std::endl;
  std::cout << *b << std::endl;

  Test t;
  GetMsg(t);

  return 0;
}
