#include <iostream>
#include <vector>
#include <typeinfo>

void test01() {
  auto a = 100;            
  // auto b;                   //error
  auto c = 3.1415926;
  auto d = "Hello";           //const char *
  auto e = &a;
  auto f = &d;
  std::cout << typeid(a).name() << std::endl;
  std::cout << typeid(c).name() << std::endl;
  std::cout << typeid(d).name() << std::endl;
  std::cout << typeid(e).name() << std::endl;
  std::cout << typeid(f).name() << std::endl;

  int temp = 100;
  const auto g = temp;    //g == const int         auto == int
  auto h = g;             //h == const int         auto == const int
}

class Test{
 public:
  int num1 = 1;
  static int num2;
  // auto num3 = 3;
  // static auto num4;
  static const auto num5 = 5;
};
int Test::num2 = 2;

template<typename T>
class Person{
 public:
  Person() {
    std::cout << "class Person" << std::endl;
  }
};

void test02() {
  std::cout << Test::num5 << std::endl;

  int arr[5] = {1, 2, 3, 4, 5};
  // auto arr[5] = {1, 2, 3, 4, 5};

  Person<int> p;
  Person<int> test01 = p;
  // Person<auto> test01 = p;
}

int main() {
  test01();
  test02();

  return 0;
}