#include <iostream>

void variadic_print() {}

template <typename T, typename... Types>
void variadic_print(const T& first_arg, const Types&... args) {
  std::cout << first_arg << std::endl;
  variadic_print(args...);
}

int main(int argc, char **argv) {
  variadic_print("lalala", 111, "hello_world");

  return 0;
}