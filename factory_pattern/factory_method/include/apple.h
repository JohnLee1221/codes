#ifndef FACTORY_MOTHED_APPLE_H_
#define FACTORY_MOTHED_APPLE_H_

#include <iostream>
#include "product.h"

class Apple : public Product {
 public:
  Apple(const std::string& brand, const int& value) : Product(brand, value) {}
  bool Producting() override;
  void PrintInfo() override;
};

#endif // FACTORY_MOTHED_APPLE_H_