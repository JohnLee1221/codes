#include <iostream>

// class MyClass {
//  public:
//   MyClass() noexcept {
//     std::cout << "Constructor" << std::endl;
//   }

//   ~MyClass() {
//     std::cout << "Distructor" << std::endl;
//   }
// };

// int main() {
//   try {
//     MyClass my_class;
//     throw 1;
//   } catch (int e) {
//     std::cerr << "Caught exception" << e << std::endl;
//   }

//   return 0;
// }

#include <iostream>

using namespace std;

struct MyException
{
    MyException(string s) :msg(s) {}
    string msg;
};

double divisionMethod(int a, int b) noexcept
{
    if (b == 0)
    {
        cout << "division by zero!!!" << endl;
        return -1;
    }
    return a / b;
}

int main()
{
    try
    {	
        double v = divisionMethod(100, 0);
        cout << "value: " << v << endl;
    }
    catch (int e)
    {
        cout << "catch except: "  << e << endl;
    }
    catch (MyException e)
    {
        cout << "catch except: " << e.msg << endl;
    }
    return 0;
}
