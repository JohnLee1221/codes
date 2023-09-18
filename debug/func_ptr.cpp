#include <iostream>

class Test {
 public:
  void PrintMessage(const std::string& message) {
    std::cout << message << std::endl;
  }
};

using FuncPtr = void(Test::*)(const std::string&);

void Callback(FuncPtr callback) {
  std::cout << "step 1" << std::endl;
  Test t;
  std::string str = "Hello";
  (t.*callback)(str);
}

int main() {
  
  Callback(&Test::PrintMessage);

  return 0;
}