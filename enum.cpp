#include <iostream>

enum Color {
  RED,
  BLUE,
  GREEN
};

using namespace std;
int main()
{
  Color key = Color::RED;
  switch (key) {
    case RED:
      std::cout << "1" << std::endl;
      break;
    case Color::BLUE:
      std::cout << "2" << std::endl;
      break;
    case Color::GREEN:
      std::cout << "3" << std::endl;
      break;
    default:
      std::cout << "error" << std::endl;
      break;
  }
}