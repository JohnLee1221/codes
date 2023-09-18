#include <iostream>

// bool EndWith(std::string str1, std::string str2) {
//   // size_t size = str1 + str2;

// }

int main() {
  std::string str1 = "Hello.bin";
  std::string str2 = "bi";

  const char *str = "Hello World";

  if (str1.substr(str1.size() - str2.size(), str2.size()) == str2) {
    std::cout << "yes" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }




  return 0;
}