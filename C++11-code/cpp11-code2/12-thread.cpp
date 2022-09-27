#include <iostream>
#include <thread>
using namespace std;

#if 0
void func()
{
    cout << "我是子线程, 叫做蒙奇D路飞..." << this_thread::get_id() << endl;
}

void func1(string name, int age)
{
    cout << "我是子线程, 叫做" << name << ", age: " << age << this_thread::get_id() << endl;
}

void threadTest()
{
    cout << "主线程id: " << this_thread::get_id() << endl;
    // 1. 创建空的线程对象
    thread t1;

    // 2. 创建一个可用的子线程
    thread t2(func);

    thread t3(func1, "漩涡鸣人", 18);

    thread t4([=](int id)
        {
            cout << "arg id: " << id << "thread id: " << this_thread::get_id() << endl;
        }, 1001);

    thread&& t5 = move(t4);

    t2.join();
    t3.join();

    t5.detach();
    cout << "t5 thead id: " << t5.get_id() << "xxxxxxxxxxx" << endl;
    t5.join();
}

int main()
{
    thread t1;
    cout << "t1 joinable: " << t1.joinable() << endl;

    thread t2(func);
    cout << "before t2 joinable: " << t2.joinable() << endl;
    t2.join();
    cout << "after t2 joinable: " << t2.joinable() << endl;


    thread t3(func);

    t3.detach();
    cout << "t3 joinable: " << t3.joinable() << endl;

    return 0;
}
#endif