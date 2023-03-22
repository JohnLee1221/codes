#include <iostream>

#if 0
struct Person {
  int num_ = 111;
  std::string str_ = "hello";
};

struct Son {
  int num_ = 222;
};

//虚基类模板
template<typename T1, typename T2>
class Base {
 public:
  Base(T1 a, T2 b) : t1_data_(a), t2_data_(b) {} 
  virtual void conver() = 0;
 public:
  T1 t1_data_;
  T2 t2_data_;
};

//派生类模板
template<typename T1, typename T2>
class Derived_1 : public Base<T1 ,T2> {
 public:
  Derived_1(T1 a, T2 b) : Base<T1, T2>(a, b) {}
  void conver() override {
    std::cout << "int data type" << std::endl;
    std::cout << "t1_data_:\t" << this->t1_data_ << std::endl;
    std::cout << "t1_data_:\t" << this->t2_data_ << std::endl;
  }
};

//派生类模板特化
class Derived_2 : public Base<Person, Son> {
 public:
  Derived_2(Person a, Son b) : Base<Person, Son>(a, b) {}
  void conver() override {
    std::cout << "personal data type" << std::endl;
    std::cout << "Person num_:\t" << this->t1_data_.num_ << std::endl;
    std::cout << "Person str_:\t" << this->t1_data_.str_ << std::endl;
    std::cout << "Son num_:\t" << this->t2_data_.num_ << std::endl;
  }
};

template<typename T1, typename T2>
void func(Base<T1, T2>& base) {
  base.conver();
}

int main() {
  Person p;
  Son s;

  Derived_1<int, int> test1{1,2};
  Derived_2 test2{p,s};
  func(test1);
  func(test2);

  return 0;
}
#endif 

class Base {
  template<typename T>
  void test(T t) {
    std::cout << "Hello" << std::endl;
  }
};

