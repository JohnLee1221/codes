#include <iostream>
using namespace std;

int main()
{
    int num1 = 100;
    long num2 = 100L;
    long long num3 = 100LL;
    unsigned long long num4 = 100LL;
    char a = 97;
    num4 = a;

    cout<<num1<<"\t"<<sizeof(num1)<<endl;
    cout<<num2<<"\t"<<sizeof(num2)<<endl;
    cout<<num3<<"\t"<<sizeof(num3)<<endl;
    cout<<num4<<"\t"<<sizeof(num4)<<endl;
    cout<<a<<"\t"<<sizeof(a)<<endl;

    return 0;

}