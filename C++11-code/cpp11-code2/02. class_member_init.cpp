#include <iostream>
using namespace std;
#if 0
struct Base
{
    Base() : a(250) 
    {
        //
    }
    Base(int num) : a(num) {}

    int a{ 4 };
    int b = 1;
    double cc = 1.23;
    char aa = 'a';
    string str = "hello";
    string str1{"world"};
    //string str2("hello,world");
    static int c;
    static const double d;
    static const char* const e;
    // c++98 标准: 变量是静态常量, 并且类型是整形或者枚举类型
    const static int f = 0;
};
int Base::c = 8;
const double Base::d = 3.14;
const char* const Base::e = "i am luffy";

// c++11 中在类内部有两种初始化方式: = {}

int main()
{
    Base b;
    cout << "a value: " << b.a << endl;
    return 0;
}
#endif