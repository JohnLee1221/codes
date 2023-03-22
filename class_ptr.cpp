#include <iostream>

class Person;
using Ptr = Person*;
// typedef Person *Ptr;
// typedef Person* Ptr;
// using *Ptr = Person;

class Person {
 public:
  Person(int num) : num_(num) {}
  int num_;
};




int main() {
  Ptr p = new Person(10);
  std::cout << p->num_ << std::endl;

  return 0;
}