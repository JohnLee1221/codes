#include <iostream>
#include <memory>

#define DISALLOW_COPY_AND_ASSIGN(classname);        \
 private:                                           \
  classname(const classname&);                      \
  classname& operator=(const classname&);

#define DISALLOW_EXPLICIT_CONSTRUCTOR(classname);   \
 private:                                           \
  classname();                                      \
  DISALLOW_COPY_AND_ASSIGN(classname);

#define DECLARE_SINGLETON(classname);               \
 public:                                            \
  static std::shared_ptr<classname> Instance() {    \
    std::shared_ptr<classname> instance_ptr;        \
    instance_ptr = std::make_shared<classname>();   \
    return instance_ptr;                            \
  }                                                 \
 private:

class Test {
 public:
  void Init(const std::string& message) {
    msg_ptr = std::make_shared<std::string>(message);
    std::cout << *msg_ptr << std::endl;
  }
  static void PrintMessage() {
    std::string tmp = "hello";
    Instance()->Init(tmp);
    std::cout << Instance()->str << std::endl;
  }

 private:
  std::shared_ptr<std::string> msg_ptr;
  std::string str = "hahaha";
  DECLARE_SINGLETON(Test);
};


int main() {
  Test t;
  Test::PrintMessage();

  return 0;
}