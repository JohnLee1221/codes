#ifndef FACTORY_MOTHED_HAWEI_H_
#define FACTORY_MOTHED_HAWEI_H_

#include <iostream>
#include "product.h"

class Hawei : public Product {
 public:
  Hawei(const std::string& brand, const int& value) : Product(brand, value) {}
  bool Producting() override;
  void PrintInfo() override;
};

#endif // FACTORY_MOTHED_HAWEI_H_