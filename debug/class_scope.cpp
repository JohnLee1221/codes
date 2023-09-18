#include <iostream>
using namespace std;

class Base
{
public:
    Base(int a) : m_num(a) 
    {
        cout<<m_num<<endl;
    }

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
    Base(10).test();

    return 0;
}