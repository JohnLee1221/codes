#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
#if 1

void func(int num, string str)
{
    cout << "func子线程的线程ID: " << this_thread::get_id() << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << "子线程: i = " << i << "num: "
            << num << ", str: " << str << endl;
    }
}

void func1()
{
    cout << "func1 子线程的线程ID: " << this_thread::get_id() << endl;

    for (int i = 0; i < 10; ++i)
    {
        cout << "子线程: i = " << i << endl;
    }
}

void threadCreateTest()
{
    cout << "主线程的线程ID: " << this_thread::get_id() << endl;
    thread t(func1);
    thread t1(func1);
    cout << "***线程t 的线程ID: " << t.get_id() << endl;
    cout << "***线程t1的线程ID: " << t1.get_id() << endl;

    t.join();
    t1.join();
    cout << "线程t 的线程ID: " << t.get_id() << endl;
    cout << "线程t1的线程ID: " << t1.get_id() << endl;
}


void download1()
{
    // 模拟下载, 总共耗时500ms，阻塞线程500ms
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "子线程1: " << this_thread::get_id() << ", 找到历史正文...." << endl;
}

void download2()
{
    // 模拟下载, 总共耗时300ms，阻塞线程300ms
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "子线程2: " << this_thread::get_id() << ", 找到历史正文...." << endl;
}

void doSomething()
{
    cout << "集齐历史正文, 呼叫罗宾...." << endl;
    cout << "历史正文解析中...." << endl;
    cout << "起航，前往拉夫德尔...." << endl;
    cout << "找到OnePiece, 成为海贼王, 哈哈哈!!!" << endl;
    cout << "若干年后，草帽全员卒...." << endl;
    cout << "大海贼时代再次被开启...." << endl;
}

void joinTest()
{
    thread t1(download1);
    thread t2(download2);
    thread t3;

    cout << "t1 thread id: " << t1.get_id() << endl;
    if (t1.get_id() == thread::id())
    {
        cout << "oooooooooooooooooohhhhhhhhhhh" << endl;
    }

    //if (t3.get_id() == thread::id())
    //{
    //    cout << "xxxxxxxxxxxxxxxxxxxx" << endl;
    //}
    // 阻塞主线程，等待所有子线程任务执行完毕再继续向下执行
    t1.join();
    t2.join();
    doSomething();
}

void detachTest()
{
    cout << "主线程的线程ID: " << this_thread::get_id() << endl;
    thread t(func, 520, "i love you");
    thread t1(func1);
    cout << "***线程t 的线程ID: " << t.get_id() << endl;
    cout << "***线程t1的线程ID: " << t1.get_id() << endl;
    t.detach();
    t1.detach();

    cout << "线程t 的线程ID: " << t.get_id() << endl;
    cout << "线程t1的线程ID: " << t1.get_id() << endl;

    // 让主线程休眠, 等待子线程执行完毕
    this_thread::sleep_for(chrono::seconds(5));
}

void foo()
{
    this_thread::sleep_for(std::chrono::seconds(1));
}

void joinableTest()
{
    thread t;
    cout << "before starting, joinable: " << t.joinable() << endl;
    if (t.get_id() == thread::id())
    {
        cout << "xxxxxxxxxxxxxxxxxxxxx t is null thread" << endl;
    }

    t = thread(foo);
    cout << "after starting, joinable: " << t.joinable() << endl;
    if (t.get_id() == thread::id())
    {
        cout << "t is a work thread" << endl;
    }

    t.join();
    cout << "after joining, joinable: " << t.joinable() << endl;

    thread t1(foo);
    cout << "after starting, joinable: " << t1.joinable() << endl;
    t1.detach();
    cout << "after detaching, joinable: " << t1.joinable() << endl;



}

void concurrency()
{
    int num = thread::hardware_concurrency();
    cout << "concurrency number: " << num << endl;
}


int main()
{
    joinableTest();
    return 0;
}
#endif