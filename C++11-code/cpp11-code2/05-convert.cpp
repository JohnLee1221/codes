#include <iostream>
#include <string>
using namespace std;

#if 0
// 数值转字符串类型
void numberToString()
{
    long double dd = 3.1415926789;
    string pi = "pi is " + to_string(dd);
    string love = "love is " + to_string(13.14);
    cout << pi << endl;
    cout << love << endl << endl;
}

// 字符串转数值类型
void stringToNumber()
{
    string str_dec = "2022.02.04, Beijing Winter Olympics";
    string str_hex = "40c3";
    string str_bin = "-10010110001";
    string str_auto = "0x7f";

    size_t sz;
    int i_dec = stoi(str_dec, &sz);
    int i_hex = stoi(str_hex, nullptr, 16);
    int i_bin = stoi(str_bin, nullptr, 2);
    int i_auto = stoi(str_auto, nullptr, 0);

    cout << "..... sz = " << sz << endl;
    cout << str_dec << ": " << i_dec << endl;
    cout << str_hex << ": " << i_hex << endl;
    cout << str_bin << ": " << i_bin << endl;
    cout << str_auto << ": " << i_auto << endl;
}

class Test
{
public:
    Test() = default;
    Test(int a) {}
};
int main()
{
    numberToString();
    stringToNumber();
    cout << endl;
    cout << "Test is pod type? " << is_trivial<Test>::value << endl;
    return 0;
}
#endif