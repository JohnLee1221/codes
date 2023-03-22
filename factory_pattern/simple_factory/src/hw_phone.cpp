#include <iostream>
#include "hw_phone.h"


HwPhone::HwPhone(std::string name, int value) : Phone(name,value) {
  std::cout << "phone's brand : " << name_ << std::endl;
  std::cout << "value is : " << value_ << std::endl;
}

void HwPhone::Info() {
  std::cout << "get a HW_phone" << std::endl;
}
