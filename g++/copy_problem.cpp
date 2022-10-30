#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Base
{
public:
    Base(int num)
    {
        p = &num;
        cout<<p<<endl;
    }

    Base(const Base &b)
    {
        //p = new int(*b.p);
        //p = b.p;
        auto a = new int(*b.p);
        p = a;
        cout<<"copy_construct_function"<<endl;
        cout<<p<<endl;
    }

    ~Base()
    {
        if (p != nullptr)
        {
            delete p;
            p = nullptr;
        }
        cout<<"distruct_function"<<endl;
    }

public:
    int *p = new int();
};

int main()
{
    Base b(333);
    Base b2 = b;

    return 0;
}