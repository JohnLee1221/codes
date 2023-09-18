#include <iostream>
#include <queue>//使用队列需要引用<queue>头文件
#include <string>

int main() {
  std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> p;
  p.push("1");
  p.push("Lelo");
  p.push("0");

  while (!p.empty()) {
    std::cout << p.top() << std::endl;
    p.pop();
  }

  return 0;
}