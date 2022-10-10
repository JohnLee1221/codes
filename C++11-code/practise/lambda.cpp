#include <iostream>
#include <functional>
using namespace std;

class Test
{
public:
    void output(int x,int y)
    {
        //这个方法中，一共能使用3个变量 x,y,m_num1
        //auto t0 = [](){return m_num1;};                              //error

        //函数体}后直接()，匿名函数定义后直接调用，t1的到是return的值
        cout<<"直接调用："<<[=]{return x + y + m_num1;}()<<endl;
        
        //匿名函数的定义，并没有调用，t1_1是自动推导成名函数的仿函数,后续的t1_1()是调用仿函数
        auto t1 = [=]{return x + y + m_num1 + 1;}; 
        cout<<"自动类型推导后,通过t1调用: "<<t1()<<endl;

        auto t2 = [&]{return x + y + m_num1;}();
        auto t3 = [this]{return m_num1;}();
        auto t4 = [this,x,y]{return x + y + m_num1;}();
    }
public:
    int m_num1 = 100;
};

void func()
{
    int a = 10;
    int b = 20;

    //当捕获列表为空时，匿名函数可以做为一个函数指针
    using ptr = int (*) (int);
    ptr p1 = [](int num){return ++num;};     
    //ptr p2 = [=](int num){return ++num;};                 //error     捕获列表有捕获时，不能作为函数指针
    cout<<"匿名函数作为函数指针: "<<p1(1000)<<endl;

    //当捕获列表捕获到外部变量，通过auto自动类型推导，生成的是一个仿函数
    auto p3 = [=](int num) mutable {return ++num + a + b;}; 
    cout<<"匿名函数作为仿函数: "<<p3(1)<<endl;

    //包装器直接把匿名函数包装成一个类
    function<int(int)> foo1 = [=](int num) mutable {return ++num + a + b;}; 
    cout<<"foo1: "<<foo1(1)<<endl;

    //绑定器把匿名函数绑定成一个仿函数，包装器再把这个仿函数包装成一个类 
    function<int(int)> foo2 = bind([=](int num) mutable {return ++num + a + b;},placeholders::_1);
    cout<<"foo2: "<<foo2(2)<<endl;
}

int main()
{
    Test test;
    test.output(1,1000000);

    func();
    
    return 0;
}