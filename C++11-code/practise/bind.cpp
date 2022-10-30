#include <iostream>
#include <functional>
using namespace std;

typedef void (*Pf)(string,int);                                 //定义一个函数指针类型

void func1(string str,int num)                                  //可调用对象：普通函数
{
    cout<<str<<"\t"<<num<<endl;
}

Pf p_func1 = func1;                                                 //可调用对象：函数指针

class Base
{
public:
    static void test01(string name,int age)     //静态成员函数
    {
        cout<<name<<"\t"<<age<<endl;
    }

    void test02(int a)
    {
        cout<<a<<endl;
    }

    //仿函数
    void operator()(string str) {cout<<str<<endl;}                          //可调用对象，2.仿函数

public:
    int m_num = 10;
};

int main()
{
    auto f1 = bind(func1,placeholders::_1,placeholders::_2);                                
    std::function<void(string,int)> f1_1 = bind(func1,placeholders::_1,placeholders::_2);     //这两种方法都可以
    f1("普通函数绑定调用",1);

    Base b;
    auto f2 = bind(b,placeholders::_1);                                        
    f2("仿函数绑定调用");
}