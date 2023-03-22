#include <iostream>
#include "phone.h"

class HwPhone : public Phone {
 public:
  HwPhone(std::string name, int value);
  void Info() override;
};