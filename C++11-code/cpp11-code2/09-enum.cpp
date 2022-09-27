#include <iostream>
using namespace std;

#if 0
enum TestColor:char{Red='a', Green, Blue};
enum class Color:char{ Red, Green, Blue };
enum struct Color1 { Red, Green, Blue };


class Test
{
public:
    Test() {}
    static void print() {}
    std::string str;
};

int main()
{
    cout << "TestColor Red: " << Red << ", " << TestColor::Red << endl;
    cout << "TestColor red size: " << sizeof(Red) << endl;
    cout << "red: " << (int)Color::Red << endl;
    int m = (int)Color::Green;
    cout << "Color size: " << sizeof(Color::Red) << endl;
    cout << "Color1 size: " << sizeof(Color1::Red) << endl;
    Test::print();
    return 0;
}
#endif