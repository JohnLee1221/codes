#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class Calculate
{
public:
    void func1()
    {   
        mx.lock();
        for(int i = 0;i < 1000000;i++)  {num++;}
        std::this_thread::sleep_for(std::chrono::seconds(3));
        mx.unlock();
        std::cout<<num<<std::endl;
    }

    void func2()
    {
        for(int i = 0;i < 1000000;i++)
        {
            std::lock_guard<std::mutex> guard(mx);      //guardËø
            num ++;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }

    void func3()
    {
        while(1)
        {
            if(mx.try_lock() ==1)
            {
                std::cout<<"thread try lock OK"<<std::endl;
                for(int i = 0;i < 100;i++)  {num ++;}
                mx.unlock();
                
                std::cout<<num<<"\t*****"<<std::endl;
                break;
            }
            else
            {
                std::cout<<"thread try lock Error"<<std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }

public:
    int num = 0;
    std::mutex mx;
};

int main()
{
    Calculate demo;

    std::thread t1(&Calculate::func1,&demo);
    // std::thread t2(&Calculate::func2,&demo);
    std::thread t3(&Calculate::func3,&demo);

    if (t1.joinable())  {t1.join();}
    // if (t2.joinable())  {t2.join();}
    if (t3.joinable())  {t3.join();}
    
    std::cout<<"main : "<<demo.num<<std::endl;

    return 0;
}