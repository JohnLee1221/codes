#include <iostream>
#include <memory>
#include "phone.h"
#include "factory.h"

int main() {
  // std::shared_ptr<Phone> phone = std::make_shared<Phone>();
  std::shared_ptr<Phone> phone = std::make_shared<Phone>(nullptr)
  // phone = Factory::Product(Brand::Iphone);
  // phone->Info();
  // phone = Factory::Product(Brand::HuaWei);
  phone->Info();

  return 0;
}