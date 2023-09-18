#include <iostream>
#include <string>

int main() {
  std::string str1 = R"(hello\nworld.)";
  std::cout << str1 << std::endl;

  std::string str2 = "<html>\
                      <head>\
                      <body>\
                      !!!";
  std::string str3 = "<html>  \
                      <head>  \
                      <body>  \
                      !!!";
  std::cout << str2 << std::endl;
  std::cout << str3 << std::endl;
  std::string str = R"(<html>
        <head>
        <title>
        </title>
        </head>
        <body>
        <p>
        </p>
        </body>
        </html>)";
  std::cout << str << std::endl;

  std::cout << "This is a newline\nThis is a tab\tThis is a backslash: \\" << std::endl;
  std::cout << R"(\)" << std::endl;
  std::cout << "\\" << std::endl;
  
  std::cout << "hello" \
            << "world" \
            << "lalala" \
            << std::endl;
  std::cout << "hello"
            << "world"
            << "lalala"
            << std::endl;

  return 0;
}