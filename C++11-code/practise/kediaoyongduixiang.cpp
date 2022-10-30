#include <iostream>
using namespace std;

typedef void (*pf)(string,int);                                 //定义一个函数指针类型

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
    operator pf() {return test01;}                                          //可调用对象，3.转换成函数指针的类对象

public:
    int m_num = 10;
};

void func1()
{
    pf p = [](string a,int b){cout<<"没有捕获列表的函数指针"<<endl;};          //可调用对象，1.函数指针
    p("hahaha",1);
}

void func2()
{  
    //可调用对象，4.类成员函数指针或者类成员变量指针
    Base b;
    void (Base::*pf_01)(int) = &Base::test02;                                 //4.1 类成员函数指针
    (b.*pf_01)(1);                                                            //调用

    using Pf_02 = void (Base::*)(int);                                       //使用using        
    Pf_02 pf_02 = &Base::test02;
    (b.*pf_02)(2);

    int Base::*pf_03 = &Base::m_num;                                          //4.2 类成员变量指针
    cout<<b.*pf_03<<endl;
}

int main()
{
    func1();
    func2();

    return 0;
}