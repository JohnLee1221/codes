#include <iostream>
using namespace std;


#if 0
// 1. final 修饰函数, 修饰类
// 2. override 对函数名的检测
class Base
{
public:
    virtual void hello() 
    {
        cout << "hello - Base class...";
    }

    virtual void world()
    {
        cout << "world - Base class...";
    }

    void print()
    {
        cout << "hello, world..." << endl;
    }
};

class Child final: public Base
{
public:
    void hello() override
    {
        cout << "hello - Child class..." << endl;
    }

    void world() final
    {
        cout << "world - Child class..." << endl;
    }

    void print()
    {
        cout << "你好,世界..." << endl;
    }
};

class GrandChild : public Child
{
public:
    void hello()
    {
        cout << "hello - GrandChild class...";
    }
#if 1
    void world()
    {
        cout << "world - GrandChild class..." << endl;
    }
#endif
};


int main()
{
	return 0;
}

#endif