#include <iostream>
#include <memory>

class Singleton {
 public:
  static std::shared_ptr<Singleton> GetInstance() {
    return singleton_;
  }

  int GetNum() { return GetInstance()->num_; }

 private:
  Singleton(const Singleton&);
  Singleton& operator= (const Singleton&);

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