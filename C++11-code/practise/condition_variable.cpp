#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <chrono>
using namespace std;

class TaskVector
{
public:
    void input(const int &num)
    {
        while (1)
        {
            unique_lock<mutex> locker(mx);          
            // if (Task.size() == max_size)         
            while (Task.size() == max_size)
            {   
                cout<<"TaskVector is full\n";
                producer.wait(locker);
            }
            Task.push_back(num);
            consumer.notify_all();

            cout<<"input_thread:  "<<this_thread::get_id()<<"\tTaskVector size: "<<Task.size()<<endl;

            this_thread::sleep_for(chrono::milliseconds(50));
        }
        
    }

    void output()
    {
        while (1)
        {
            unique_lock<mutex> locker(mx);
            // if (Task.empty())
            while (Task.empty())
            {
                cout<<"TaskVector is empty\n";
                consumer.wait(locker);
            }
            Task.pop_back();
            producer.notify_all();

            cout<<"output_thread: "<<this_thread::get_id()<<"\tTaskVector size: "<<Task.size()<<endl;

            this_thread::sleep_for(chrono::milliseconds(50));
        }
 
    }

private:
    int max_size = 10;
    vector<int> Task;
    mutex mx;
    condition_variable producer;
    condition_variable consumer;
};

int main()
{
    TaskVector taskDemo;
    thread input_thread[10];
    thread output_thread[2];

    for (int ii = 0;ii < 10;ii++)
    {
        input_thread[ii] = thread(&TaskVector::input,&taskDemo,188);
    }

    for(int jj = 0;jj < 2;jj++)
    {
        output_thread[jj] = thread(&TaskVector::output,&taskDemo);
    }

    for(int ii = 0;ii < 10;ii++)    {input_thread[ii].join();}
    for(int jj = 0;jj < 2;jj++)     {output_thread[jj].join();}

    return 0;
}

