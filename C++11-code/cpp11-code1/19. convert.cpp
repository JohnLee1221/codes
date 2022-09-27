#include <iostream>
#include <string>
using namespace std;

#if 0
// 数值转字符串类型
void numberToString()
{
    long double dd = 3.1415926789;
    string pi = "pi is " + to_string(dd);
    string love = "love is " + to_string(97);
    cout << pi << endl;
    cout << love << endl;
}

// 字符串转数值类型
void stringToNumber()
{
    string str_dec = "20013, A Space Odyssey";
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
int main()
{
    numberToString();
    stringToNumber();
    return 0;
}
#endif