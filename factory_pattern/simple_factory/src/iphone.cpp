#include <iostream>
#include "iphone.h"


Iphone::Iphone(std::string name, int value) : Phone(name,value) {
  std::cout << "phone's brand : " << name_ << std::endl;
  std::cout << "value is : " << value_ << std::endl;
}
void Iphone::Info() {
  std::cout << "get an Iphone." << std::endl;
}
