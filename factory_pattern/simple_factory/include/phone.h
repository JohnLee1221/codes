#ifndef SIMPLE_FACTORY_PHONE_H_
#define SIMPLE_FACTORY_PHONE_H_

#include <iostream>

class Phone {
 public:
  Phone() = default;
  Phone(std::string name, int value) : name_(name), value_(value) {}

  virtual void Info() = 0;
 protected:
  std::string name_;
  int value_;
};

#endif  // SIMPLE_FACTORY_PHONE_H_