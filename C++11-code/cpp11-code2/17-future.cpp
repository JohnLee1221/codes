#include <iostream>
#include <thread>
#include <future>
using namespace std;

void func(promise<string>& p)
{
    this_thread::sleep_for(chrono::seconds(3));
    p.set_value("我是路飞，要成为海贼王。。。");
    this_thread::sleep_for(chrono::seconds(1));
}

string myFunc()
{
    this_thread::sleep_for(chrono::seconds(3));
    return "我是路飞，要成为海贼王。。。";
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
    cout << "主线程线程ID: " << this_thread::get_id() << endl;
    future<string> f = async(launch::deferred, [](int number) {
        cout << "子线程线程ID: " << this_thread::get_id() << endl;
        return string("我是海贼王...") + to_string(number);
        }, 100);

    this_thread::sleep_for(chrono::seconds(10));
    cout << "子线程的返回值: " << f.get() << endl;

    //future_status status;
    //do 
    //{
    //    status = f.wait_for(chrono::seconds(1));
    //    if (status == future_status::deferred)
    //    {
    //        cout << "子线程还没有执行..." << endl;
    //        f.wait();
    //    }
    //    else if (status == future_status::ready)
    //    {
    //        cout << "数据就绪了, 子线程返回的数据是: " << f.get() << endl;
    //    }
    //    else if (status == future_status::timeout)
    //    {
    //        cout << "子线程还在执行, 超时时长用完了, 继续等待..." << endl;
    //    }

    //} while (status != future_status::ready);
#if 0
    // 普通函数
    packaged_task<string(void)> task1(myFunc);
    // 匿名函数
    packaged_task<int(int)> task2([](int arg) {
        return 100;
        });
    // 仿函数
    Base ba;
    packaged_task<string(string)> task3(ba);

    // 将类对象进行转换得到的函数指针
    Base bb;
    packaged_task<string(string, int)> task4(bb);
    // 静态函数
    packaged_task<string(string, int)> task5(&Base::showMsg);
    // 非静态函数
    Base bc;
    auto obj = bind(&Base::getNumber, &bc, placeholders::_1);
    packaged_task<int(int)> task6(obj);

    thread t1(ref(task6), 200);
    future<int> f = task6.get_future();
    int num = f.get();
    cout << "子线程返回值: " << num << endl;
    t1.join();
#endif

#if 0
    promise<string> pro;
    //thread t1(func, ref(pro));
    thread t2([](promise<string>& p) {
        this_thread::sleep_for(chrono::seconds(3));
        p.set_value("我是路飞，要成为海贼王。。。");
        this_thread::sleep_for(chrono::seconds(1));
        }, ref(pro));
    future<string> f = pro.get_future();
    string str = f.get();
    cout << "子线程返回的数据: " << str << endl;
    t2.join();
#endif
    return 0;
}

操作系统版本不同, 数据库版本不同, Qt版本不同, Qt版本相同编译套件又不同,

编译对应的数据库驱动需要数据库提供的动态库,
- Qt编译套件的位数需要和数据库驱动的位数相同
- 都是32位或都是64位