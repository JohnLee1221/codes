#include <iostream>
#include "factory.h"
#include "iphone.h"
#include "hw_phone.h"

Phone* Factory::Product(Brand brand) {
  Phone* phone;
  switch (brand) {
    case Brand::HuaWei:
      phone = new HwPhone("HuaWei",5000);
      break;
    case Brand::Iphone:
      phone = new Iphone("Apple",8000);
      break;
    default:
      std::cout << "error" << std::endl;
  }
  return phone;
}
