#include <iostream>
using namespace std;

class Base
{
public:
    Base():p(new int(100))
    {
        cout<<*p<<endl;
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
        delete p;
        cout<<"distruct function"<<endl;
    }

public:
    int* p = nullptr;
};

int main()
{
    //Base b1;
    //Base b2 = b1;
    Base b3 = Base();

    return 0;
}