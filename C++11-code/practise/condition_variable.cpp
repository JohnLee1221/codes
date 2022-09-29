#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mx;
condition_variable host;

void func1()
{
    mx.lock();                           //第一线程获得锁，在不解锁的情况下，后续线程无法获得锁
    cout<<this_thread::get_id()<<endl;
    // mx.unlock();
}

void func2()
{
    unique_lock<mutex> locker(mx);      //第一个线程获得锁
    cout<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    host.wait(locker);                  //进入wait()函数后会释放锁，并进入wait状态，等待notify
}

void func3()
{
    lock_guard<mutex> locker(mx);       //第一个线程获得锁，当函数结束时，lock_guard会解锁并析构掉mutex类
    cout<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::seconds(1));
}

int main()
{   
    thread t[5];

    // for(int i = 0;i < 5;i++) {t[i] = thread(func1);}
    for(int i = 0;i < 5;i++) {t[i] = thread(func2);}
    // for(int i = 0;i < 5;i++) {t[i] = thread(func3);}
    for(int i = 0;i < 5;i++) {t[i].join();}

    return 0;
}

