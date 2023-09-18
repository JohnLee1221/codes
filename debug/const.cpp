#include <iostream>

class Person {
 public:
  Person(int age, std::string name): age_(age), name_(name) {}

 const std::string& get_name() const {
    return name_;
  }

 private:
  int age_;
  std::string name_;
};

void Msg(const Person& p) {
  // std::cout << p.get_name() << std::endl;
  // name = "Jerry";
  // p.get_name() = "Jerry";
  std::cout << p.get_name() << std::endl;
}

int main() {
  Person p(18, "Tom");
  Msg(p);
  // std::cout << p.get_name() << std::endl;

  return 0;
}