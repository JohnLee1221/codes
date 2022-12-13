#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Base
{
public:
    Base(string name,int age) : m_name(name),m_age(age)
    {
        cout<<"construct_function"<<endl;
    }

    Base(const Base &b)
    {
        m_name = b.m_name;
        m_age = b.m_age;
        cout<<"copy_construct_function"<<endl;
    }

    ~Base()
    {
        cout<<"distruct_function"<<endl;
    }

public:
    string m_name;
    int m_age;
};

void func(Base b)
{
    cout<<b.m_name<<"\t"<<b.m_age<<endl;
}

Base func2()
{
    Base b("Jerry",18);
    return b;
}

int main()
{
    Base b1("Tom",20);
    Base b2 = b1;                                               //b1初始化b2对象，会调用拷贝构造函数
    cout<<b1.m_name<<endl;
    b2.m_name = "hahaha";
    cout<<b1.m_name<<endl;

    func(b2);                                                   //b2以值传递的方式，传递Base对象，会调用拷贝构造函数，fun执行完b2就进行析构
    
    //g++添加-fno-elide-constructors关闭RVO优化
    func2();                                                    //func2()以返回值的方式，返回一个Base对象，调用拷贝构造函数，编译器默认优化
                                                                
    return 0;
}