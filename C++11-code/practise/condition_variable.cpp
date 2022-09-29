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
    mx.lock();                           //��һ�̻߳�������ڲ�����������£������߳��޷������
    cout<<this_thread::get_id()<<endl;
    // mx.unlock();
}

void func2()
{
    unique_lock<mutex> locker(mx);      //��һ���̻߳����
    cout<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    host.wait(locker);                  //����wait()��������ͷ�����������wait״̬���ȴ�notify
}

void func3()
{
    lock_guard<mutex> locker(mx);       //��һ���̻߳����������������ʱ��lock_guard�������������mutex��
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

