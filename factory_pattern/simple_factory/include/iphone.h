#include <iostream>
#include "phone.h"

class Iphone : public Phone {
 public:
  Iphone(std::string name, int value);
  void Info() override;
};