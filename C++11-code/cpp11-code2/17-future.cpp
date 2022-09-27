#include <iostream>
#include <thread>
#include <future>
using namespace std;

void func(promise<string>& p)
{
    this_thread::sleep_for(chrono::seconds(3));
    p.set_value("����·�ɣ�Ҫ��Ϊ������������");
    this_thread::sleep_for(chrono::seconds(1));
}

string myFunc()
{
    this_thread::sleep_for(chrono::seconds(3));
    return "����·�ɣ�Ҫ��Ϊ������������";
}

using funcPtr = string(*)(string, int);
class Base
{
public:
    string operator()(string msg)
    {
        string str = "operator() function msg: " + msg;
        return str;
    }

    operator funcPtr()
    {
        return showMsg;
    }

    int getNumber(int num)
    {
        int number = num + 100;
        return number;
    }

    static string showMsg(string msg, int num)
    {
        string str = "showMsg() function msg: " + msg + ", " + to_string(num);
        return str;
    }
};

int main()
{
    cout << "���߳��߳�ID: " << this_thread::get_id() << endl;
    future<string> f = async(launch::deferred, [](int number) {
        cout << "���߳��߳�ID: " << this_thread::get_id() << endl;
        return string("���Ǻ�����...") + to_string(number);
        }, 100);

    this_thread::sleep_for(chrono::seconds(10));
    cout << "���̵߳ķ���ֵ: " << f.get() << endl;

    //future_status status;
    //do 
    //{
    //    status = f.wait_for(chrono::seconds(1));
    //    if (status == future_status::deferred)
    //    {
    //        cout << "���̻߳�û��ִ��..." << endl;
    //        f.wait();
    //    }
    //    else if (status == future_status::ready)
    //    {
    //        cout << "���ݾ�����, ���̷߳��ص�������: " << f.get() << endl;
    //    }
    //    else if (status == future_status::timeout)
    //    {
    //        cout << "���̻߳���ִ��, ��ʱʱ��������, �����ȴ�..." << endl;
    //    }

    //} while (status != future_status::ready);
#if 0
    // ��ͨ����
    packaged_task<string(void)> task1(myFunc);
    // ��������
    packaged_task<int(int)> task2([](int arg) {
        return 100;
        });
    // �º���
    Base ba;
    packaged_task<string(string)> task3(ba);

    // ����������ת���õ��ĺ���ָ��
    Base bb;
    packaged_task<string(string, int)> task4(bb);
    // ��̬����
    packaged_task<string(string, int)> task5(&Base::showMsg);
    // �Ǿ�̬����
    Base bc;
    auto obj = bind(&Base::getNumber, &bc, placeholders::_1);
    packaged_task<int(int)> task6(obj);

    thread t1(ref(task6), 200);
    future<int> f = task6.get_future();
    int num = f.get();
    cout << "���̷߳���ֵ: " << num << endl;
    t1.join();
#endif

#if 0
    promise<string> pro;
    //thread t1(func, ref(pro));
    thread t2([](promise<string>& p) {
        this_thread::sleep_for(chrono::seconds(3));
        p.set_value("����·�ɣ�Ҫ��Ϊ������������");
        this_thread::sleep_for(chrono::seconds(1));
        }, ref(pro));
    future<string> f = pro.get_future();
    string str = f.get();
    cout << "���̷߳��ص�����: " << str << endl;
    t2.join();
#endif
    return 0;
}

����ϵͳ�汾��ͬ, ���ݿ�汾��ͬ, Qt�汾��ͬ, Qt�汾��ͬ�����׼��ֲ�ͬ,

�����Ӧ�����ݿ�������Ҫ���ݿ��ṩ�Ķ�̬��,
- Qt�����׼���λ����Ҫ�����ݿ�������λ����ͬ
- ����32λ����64λ