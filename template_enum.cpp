#include <typeinfo>
#include <cxxabi.h>
#include <iostream>
#include <vector>

enum class Data {
    kInt = 1,
    kDouble = 2,
    kChar = 3,
    kFloat = 4,
};

template <typename T, typename PARA, Data D>
class Test {
 public:
    void Info() {
        T t;
        t.Printf();
    }
};

int main(int argc, char **argv) {
    Data datatype;
    datatype = Data::kChar;
    switch (datatype) {
        case Data::kInt: 
            std::cout << "int" << std::endl;
            break;
        case Data::kDouble: 
            std::cout << "double" << std::endl;
            break;
        case Data::kFloat:
            std::cout << "folat" << std::endl;
            break;
        case Data::kChar:
            std::cout << "char" << std::endl;
            break;
        default:
            break;
    }

    return 0;
}
