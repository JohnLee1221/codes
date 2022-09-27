#include <iostream>
#include <thread>
#include <chrono>

void func1()
{
    std::cout<<"func1 thread id : "<<std::this_thread::get_id()<<std::endl;
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

int main()
{
    std::cout<<std::this_thread::get_id()<<std::endl;

    std::thread t1(func1);
    std::thread t2;
    t2 = std::thread(func2,"Tom",18);

    t1.detach();
    // t2.join();
    t2.detach();
    
    return 0;
}