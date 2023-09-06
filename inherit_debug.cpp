#include <iostream>
#include <vector>
#include <memory>

using SharePtr = std::shared_ptr<std::vector<int>>;

template<typename T>
class Base {
 public:
  inline Base(const T& data) : data_(data) {} 

  inline T GetPtr() {
    return data_;
  }

 protected:
  inline void Assign(const T& t) {
    data_ = t;
    std::cout << "Call assign function" << std::endl;
  }

  T data_;
};

class Derive : public Base<SharePtr> {
 public:
  inline Derive(const SharePtr& ptr) : Base(ptr) {}
};

int main(int argc, char **argv) {
  SharePtr ptr = std::make_shared<std::vector<int>>(std::vector<int>(10, 111));

  Derive derive(ptr);
  SharePtr tmp_ptr = derive.GetPtr();

  return 0;
}