#include <iostream>
#include <vector>

//stl库里面容器的遍历
void test01() {
  std::vector<int> v;
  for (int i = 0; i < 20; i++) {
    v.push_back(i);
  }

  for (auto value : v) {
    std::cout << value << "\t";
  }
  std::cout << "\n";
}

//lambda表达式
auto f = []() {
  std::cout << "Hello World." << std::endl;
};

//auto 与decltype关键字配合，推导模板参数
//返回值类型后置

int main() {
  test01();
  f();

  return 0;
}