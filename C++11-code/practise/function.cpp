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

    //把类对象转换成一个函数指针    被转换的函数要求是静态函数
    operator Pf() {return test01;}                                          //可调用对象，3.转换成函数指针的类对象

public:
    int m_num = 10;
};

int main()
{
    function<void(string,int)> function_01 = func1;
    function<void(string,int)> function_02 = p_func1;

    function_01("普通函数绑定",01);
    function_01("函数指针绑定",02);

    Base b;
    function<void(string)> function_03 = b;
    function<void(string,int)> function_04 = Base::test01;
    function_03("仿函数绑定");
    function_04("静态成员函数绑定",3);

    function<void(string,int)> function_05 = b;
    b("类转换成函数指针绑定",4);

    return 0;
}