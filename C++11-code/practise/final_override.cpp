#include <iostream>
using namespace std;

class Base
{
public:
    virtual void test()
    {
        cout<<"Base test function"<<endl;
    }
};

class Child : public Base
{
public:
    void test() override
    {
        cout<<"Child test function"<<endl;
    }
};

class GrandChild : public Child
{
public:
    void test() override
    {
        cout<<"GrandChild test function"<<endl;
    }
    
};

//void func(Base& base)
//{
//    base.test();
//}

int main()
{
    Child child;
    //func(child);
    Base * base;
    base = &child;
    base->test();

    return 0;
}
