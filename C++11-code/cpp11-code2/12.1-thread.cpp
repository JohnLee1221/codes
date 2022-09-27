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
        cout << "�ҵ�������: " << name << ", �ҽ��� " << age << " ����..." << endl;
    }

    static void message()
    {
        cout << "��������D·��, ��Ҫ��Ϊ������������!!!" << endl;
    }
};

void func()
{
    cout << "hello, ��ӭ����������!!!" << endl;
}

int main()
{
    thread t1(func);

    // ���ݾ�̬��Ա����
    thread tt(&Base::message);

    // ���ݷǾ�̬��Ա����
    Base b;
    thread t2(&Base::showMsg, b, "·��", 19);
    thread t3(&Base::showMsg, &b, "·��", 19);
    thread t4(bind(&Base::showMsg, &b, "·��", 19));
    thread t5(bind(&Base::showMsg, b, "·��", 19));

    t1.join();
    tt.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
#endif