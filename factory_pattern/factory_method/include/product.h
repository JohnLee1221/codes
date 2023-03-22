#ifndef FACTORY_MOTHED_PRODUCT_H_
#define FACTORY_MOTHED_PRODUCT_H_

#include <iostream>

class Product {
 public:
  Product(const std::string& brand, const int& value) :
      brand_(brand), value_(value) {}

  virtual bool Producting() = 0;
  virtual void PrintInfo() = 0;

 protected:
  int value_;
  std::string brand_;
  bool state_ = false;
};

#endif // FACTORY_MOTHED_PRODUCT_H_