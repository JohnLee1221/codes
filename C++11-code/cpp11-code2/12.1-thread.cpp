#include <iostream>
#include <thread>
#include <functional>
using namespace std;

#if 1
// #if 0
class Base
{
public:
    void showMsg(string name, int age)
    {
        cout << "我的名字是: " << name << ", 我今年 " << age << " 岁了..." << endl;
    }

    static void message()
    {
        cout << "我是蒙奇D路飞, 是要成为海贼王的男人!!!" << endl;
    }
};

void func()
{
    cout << "hello, 欢迎来到新世界!!!" << endl;
}

int main()
{
    thread t1(func);

    // 传递静态成员函数
    thread tt(&Base::message);

    // 传递非静态成员函数
    Base b;
    thread t2(&Base::showMsg, b, "路飞", 19);
    thread t3(&Base::showMsg, &b, "路飞", 19);
    thread t4(bind(&Base::showMsg, &b, "路飞", 19));
    thread t5(bind(&Base::showMsg, b, "路飞", 19));

    t1.join();
    tt.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
#endif