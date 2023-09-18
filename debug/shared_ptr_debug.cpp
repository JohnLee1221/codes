#include <iostream>
#include <memory>
#include <vector>

using ShardPtr = std::shared_ptr<std::vector<int>>;

template<typename T>
class Test {
 public:
  Test() = default;
  T Foo(const T& t) {
    T tmp;
    tmp = t;
    return tmp;
  }
};

int main(int argc, char **argv) {
  std::vector<int> vec = {1, 2, 4, 6, 9, 3};
  ShardPtr ptr(new std::vector<int>(vec));
  Test<ShardPtr> t;
  
  ShardPtr new_ptr = t.Foo(ptr);
  
  return 0;
}