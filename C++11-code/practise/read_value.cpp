#include <iostream>
using namespace std;

int && value = 520;

class Base
{
public:
    Base()
    {
        p = new int(100);
        cout<<"construct function"<<endl;
    }

    Base(const Base & b) : p(new int(*b.p))
    {
        cout<<"copy construct function"<<endl;
    }

    Base(Base && b) : p(b.p)
    {
        b.p = nullptr;
        cout<<"move construct function"<<endl;
    }

    ~Base()
    {
        if(p != nullptr)
        {
            delete p;
        }
        cout<<"distruct function"<<endl;
    }

public:
    int *p = nullptr;
};

int main()
{
    Base b1;                //调用默认构造
    Base b2 = b1;           //调用拷贝构造
    Base b3 = Base();       //调用移动构造

    return 0;
}