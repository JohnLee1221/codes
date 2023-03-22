#include <iostream>
#include <memory>

class Singleton {
 public:
  Singleton(const Singleton&) = delete;
  Singleton& operator= (const Singleton&) = delete;
  
  static std::shared_ptr<Singleton> GetInstance() {
    return singleton_;
  }

  int GetNum() { return num_; }

 private:
  Singleton() = default;
  static std::shared_ptr<Singleton> singleton_;
  int num_ = 10000;
};

std::shared_ptr<Singleton> Singleton::singleton_(new Singleton());

int main() {
  std::shared_ptr<Singleton> ptr = Singleton::GetInstance();
  std::cout << ptr->GetNum() << std::endl;

  return 0;
}