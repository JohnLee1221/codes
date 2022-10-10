#include <iostream>
using namespace std;

class Base
{
public:
    Base() : m_num(10) {}

    static void test()
    {
        cout<<m_str<<"\t"<<endl;
    }
public:
    int m_num;
    static string m_str;
};

string Base::m_str = "Hello";

int main()
{
    Base::test();
    Base().test();

    return 0;
}