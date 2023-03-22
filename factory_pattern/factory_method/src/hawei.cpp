#include <iostream>
#include "hawei.h"    

bool Hawei::Producting() {
  std::cout << "Start to product phone ----------> " << brand_ << std::endl;
  state_ = true;
  return state_;
}

void Hawei::PrintInfo() {
  if (state_) {
    std::cout << "Product " << brand_ << " phone Success ~" << std::endl;
    std::cout << brand_ << " phone's value is : " << value_ << std::endl;
  } else {
    std::cout << "Product " << brand_ << " phone false!!!" << std::endl;
  }
}