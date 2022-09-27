#include <iostream>
#include <thread>
using namespace std;

#if 0
void func()
{
    cout << "�������߳�, ��������D·��..." << this_thread::get_id() << endl;
}

void func1(string name, int age)
{
    cout << "�������߳�, ����" << name << ", age: " << age << this_thread::get_id() << endl;
}

void threadTest()
{
    cout << "���߳�id: " << this_thread::get_id() << endl;
    // 1. �����յ��̶߳���
    thread t1;

    // 2. ����һ�����õ����߳�
    thread t2(func);

    thread t3(func1, "��������", 18);

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