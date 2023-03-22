#include <iostream>
#include "phone.h"

enum class Brand {
  Iphone,
  HuaWei
};

class Factory {
 public:
  Factory() = default;
  static Phone* Product(Brand brand);
};