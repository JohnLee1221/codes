#include <type_traits>
#include <iostream>

class Base {};
class ClassA {};
class ClassB : public Base {};

template <typename MessageType>
bool IsDerived(typename std::enable_if<std::is_base_of<Base, MessageType>::value, MessageType>::type *message = nullptr) {
  return true;
}

template <typename MessageType>
bool IsDerived(typename std::enable_if<!std::is_base_of<Base, MessageType>::value, MessageType>::type *message = nullptr) {
  return false;
}

int main() {
  if (IsDerived<ClassA>()) {
    std::cout << "This class is a derivative of the Base class" << std::endl;
  } else {
    std::cout << "This class is not a derivative of the Base class!!!" << std::endl;
  }

  return 0;
}

