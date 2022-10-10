#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>
using namespace std;

class taskVector
{
public:
    void producer(int num)
    {
        while(1)
        {
            if(v1.size() == 10)
            {
                unique_lock<mutex> locker(mx);
                conditionVar.wait(locker);
            }

            v1.push_back(num);
            cout<<v1.size()<<endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

    void consumer()
    {
        while(1)
        {
            if(v1.size() == 0)
            {
                unique_lock<mutex> locker(mx);
                conditionVar.notify_all();
            }
            v1.pop_back();
            cout<<v1.size()<<endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

public:
    int max_size = 10;
    mutex mx;
    condition_variable conditionVar;
    vector<int> v1;
};

int main()
{
    taskVector v;
    thread t1[10];
    thread t2[5];

    for (int i = 0;i < 10;i++)
    {
        t1[i] = thread(&taskVector::producer,&v,100);
    }

    for (int j = 0;j < 5;j++)
    {
        t2[j] = thread(&taskVector::consumer,&v);
    }

    for(int i = 0;i < 10;i++) {t1[i].join();}
    for(int j = 0;j < 5;j++) {t1[j].join();}

    return 0;
}