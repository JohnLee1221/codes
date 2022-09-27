#include <iostream>
using namespace std;

#if 0
int main()
{
    // 有符号 
    long int n = 100L;
    // signed long long
    // long long int
    // signed long long int
    long long num1 = 11111LL;
    // unsigned long long int
    unsigned long long num2 = 1111ULL;

    // 占内存大小最少是 8 字节

    cout << "long long max: " << LLONG_MAX
        << ", long long min: " << LLONG_MIN
        << ", unsigned long long max: " << ULLONG_MAX << endl;

    // 低等级 int 到 高等级 int
    char c = 6;
    long long d = c;
    // 标准 int 自定义 int
    typedef int aa;
    aa bb = 5;
    int num = bb;
    long long num1 = bb;
    // 有符号int 无符号 int (内存大小相同) == > 有符号 ==> 无符号整形
    unsigned int num2 = num1;
    return 0;
}
#endif