#include <iostream>
#include <functional>

#if false
typedef std::function<void()> Callback;

class A {
 public:
  // 构造函数参数是一个包装器对象
  A(const Callback& f) : callback(f){}

  void notify() {
    callback(); // 调用通过构造函数得到的函数指针
  }
 private:
  Callback callback;
};

class B {
 public:
  void operator()() {
    std::cout << "Hello World" << std::endl;
  }
};

int main() {
  B b;
  // A a(b); // 仿函数通过包装器对象进行包装
  std::string str = "Hello World.";

  auto callback = [=]() {
                    std::cout << str << std::endl;
                  };
  A a(callback);
  a.notify();
  
  return 0;
}
#endif

#if false
using FuncPtr = void(*)(int, std::string);

class Test {
 public:
  // void operator() (int num, std::string str) {
  //   std::cout << "operator()" << std::endl;
  //   std::cout << num << "\t" << str << std::endl;
  // }

  static void print(int num, std::string str) {
    std::cout << "object method : print" << std::endl;
    std::cout << num << "\t" << str << std::endl;
  }

  operator FuncPtr() {
    std::cout << "operator FuncPtr" << std::endl;
    return print;
  }
};

int main() {
  Test t;
  t(888, "Hello");
  t.print(123, "lalala");
  t(111, "balabala");

  FuncPtr func_ptr = Test::print;
  func_ptr(1, "666");

  return 0;
}
#endif

class Person {
 public:
  void test(int a) {
    std::cout << a << std::endl;
  }
};

int main() {
  int a = 10;
  int b = 100;
  auto callback = [](int num) {
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    std::cout << num << std::endl;
  };
  std::cout << sizeof(callback) << std::endl;
  std::function<void(int)> f = callback;
  std::cout << sizeof(f) << std::endl;
  callback(888);

  std::cout << sizeof(int*) << std::endl;
  std::cout << sizeof(int) << std::endl;
  std::cout << sizeof(std::string) << std::endl;
  std::cout << sizeof(std::function<void(int)>) << std::endl;
  std::cout << sizeof(std::function<int(int)>) << std::endl;
  std::cout << sizeof(std::function<void(std::string)>) << std::endl;
  std::cout << sizeof(std::function<std::string(std::string)>) << std::endl;
  std::cout << sizeof(void(Person::*)(std::string)) << std::endl;

  return 0;
}