#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

void func1()
{
    std::cout<<"func1 thread id : "<<std::this_thread::get_id()<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(20));
}

void func2(std::string name,int age)
{
    for(int i = 100;i>0;i--)
    {
        std::cout<<"func2 name : "<<name<<"\t"<<"age : "<<age<<"times : "<<i<<std::endl;
        std::cout<<"func2 thread id : "<<std::this_thread::get_id()<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }  
}

void system_time()
{
    time_t now = time(nullptr);
    char* curr_time = ctime(&now); 
    std::cout <<"*******************************"<<curr_time <<std::endl;
}

int main()
{
    system_time();
    std::cout<<"main thread id : "<<std::this_thread::get_id()<<std::endl;

    std::thread t1(func1);
    std::thread t2;
    t2 = std::thread(func2,"Tom",18);

    // std::cout<<"thread 1 joinable() return : "<<t1.joinable()<<std::endl;
    // std::cout<<"thread 2 joinable() return : "<<t2.joinable()<<std::endl;
    // system_time();
    

    t1.join();
    system_time();
    // t2.join();
    t2.detach();
    system_time();
    // std::cout<<"thread 1 joinable() return : "<<t1.joinable()<<std::endl;
    // std::cout<<"thread 2 joinable() return : "<<t2.joinable()<<std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(50));
    
    return 0;
}