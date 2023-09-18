#include <iostream>
#include <functional>


void Test(const int& num, const std::string& str) {
  std::cout << "num :\t\t" << num << std::endl;
  std::cout << "string :\t" << str << std::endl;
}

void (*f_ptr)(const int&, const std::string&) = Test;

typedef void (*PtrType)(const int&, const std::string&);
PtrType ptr1 = Test;

using FPtr = void (*)(const int&, const std::string&);
FPtr ptr2 = Test;

auto f = [](const int& num, const std::string& str) {
  std::cout << "lambda function, num : \t\t" << num << std::endl;
  std::cout << "lambda function, string : \t" << str << std::endl;
};

void FunctionPtr(const std::function<void(const int&, const std::string&)>& func,
    const int& num, const std::string& str) {
      func(num, str);
}

auto func1 = std::bind(Test, std::placeholders::_2, std::placeholders::_1);
auto func2 = std::bind(Test, std::placeholders::_1, std::placeholders::_2);
auto func3 = std::bind(Test, 9999, "wakawaka");

int main(int argc, char ** argv) {
  Test(1000, "hello");
  f_ptr(1111, "lalala");
  ptr1(2222, "test");
  ptr2(3333, "hahaha");
  std::cout << "===============================" << std::endl;
  FunctionPtr(Test, 6666, "wawawa");
  // FunctionPtr(func1, "5555", 5555);
  func1("hello world", 8888);
  func2(7777, "hello world 02");
  func3();

  return 0;
}