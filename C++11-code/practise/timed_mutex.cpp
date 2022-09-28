#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <ctime>

std::timed_mutex g_mutex;

char* system_time()
{
    time_t now = time(nullptr);
    return ctime(&now); 

    // char* curr_time = ctime(&now); 
    // std::cout <<"*******************************"<<curr_time <<std::endl;
}

void func()
{
    std::chrono::seconds time_hold(1);

    while(true)
    {
        std::cout<<std::this_thread::get_id()<<" enter while\t"<<system_time()<<std::endl;

        if(g_mutex.try_lock_for(time_hold))     //第一个线程直接进入，第二个线程要被阻塞time_hold秒，然后在去进行lock线程
        {
            std::cout<<std::this_thread::get_id()<<" try lock is ok\t"<<system_time()<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            g_mutex.unlock();
            std::cout<<std::this_thread::get_id()<<" unlock\t"<<system_time()<<std::endl;
            break;
        }
        else
        {
            std::cout<<std::this_thread::get_id()<<" try lock is error\t"<<system_time()<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

int main()
{
    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    return 0;
}