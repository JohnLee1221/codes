#include <iostream>

struct MyException {
  MyException(std::string s) :msg(s) {}
  std::string msg;
};

double divisionMethod(int a, int b) throw(MyException, int) {
  if (b == 0) {
    throw MyException("division by zero!!!");
    // throw 100;
  }
  return a / b;
}

int main() {
  try {	
    double v = divisionMethod(100, 0);
    std::cout << "value: " << v << std::endl;
  }
  catch (int e) {
    std::cout << "catch except: "  << e << std::endl;
  }
  catch (MyException e) {
    std::cout << "catch except: " << e.msg << std::endl;
  }
  return 0;
}
