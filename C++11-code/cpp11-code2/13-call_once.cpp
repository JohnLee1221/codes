#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

#if 1
// #if 0
once_flag g_flag;
// ��дһ������ģʽ���� --> ����ģʽ
class Base
{
public:
    Base(const Base& obj) = delete;
    Base& operator=(const Base& obj) = delete;
    static Base* getInstance()
    {
        call_once(g_flag, [&]()
            {
                obj = new Base;
                cout << "ʵ�����󱻴���..." << endl;
            });
        return obj;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }
private:
    Base() {};
    static Base* obj;
    string name;
};
Base* Base::obj = nullptr;

void myFunc(string name)
{
    Base::getInstance()->setName(name);
    cout << "my name is: " << Base::getInstance()->getName() << endl;
}

int main()
{
    thread t1(myFunc, "·��");
    thread t2(myFunc, "��˹");
    thread t3(myFunc, "����");
    thread t4(myFunc, "��������");
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
#endif