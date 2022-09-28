#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>
using namespace std;
#if 1

#if 1
// ���������
class TaskQueue
{
public:
    // �������
    void put(const int& task)
    {
        while(1)
        {
            unique_lock<mutex> locker(myMutex);
            while (taskQueue.size() == maxSize)
            {
                cout<<"TaskQueue is full\n";
                notFull.wait(locker);
            }
            taskQueue.push(task);
            // cout << "�������: " << task << ", �߳�ID: " << this_thread::get_id() << endl;
            cout<<"input_thread:  "<<this_thread::get_id()<<"\tTaskQueue size: "<<taskQueue.size()<<endl;
            // ����������
            notEmpty.notify_one();

            this_thread::sleep_for(chrono::milliseconds(50));
        }

    }

    // ȡ����
    void take()
    {
        while(1)
        {
            unique_lock<mutex> locker(myMutex);
            while (taskQueue.empty())
            {
                cout<<"TaskQueue is empty\n";
                notEmpty.wait(locker);
            }

            int node = taskQueue.front();
            taskQueue.pop();
            // cout << "ɾ������: " << node << ", �߳�ID: " << this_thread::get_id() << endl;
            cout<<"output_thread: "<<this_thread::get_id()<<"\tTaskQueue size: "<<taskQueue.size()<<endl;
            // ����������
            notFull.notify_all();

            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }

    bool isFull()
    {
        lock_guard<mutex> locker(myMutex);
        if (maxSize == taskQueue.size())
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        lock_guard<mutex> locker(myMutex);
        if (taskQueue.size() == 0)
        {
            return true;
        }
        return false;
    }

    int taskSize()
    {
        lock_guard<mutex> locker(myMutex);
        return taskQueue.size();
    }
private:
    int maxSize = 10;
    queue<int> taskQueue;
    mutex myMutex;
    condition_variable notFull;     // ������
    condition_variable notEmpty;    // ������
};
#else
// ���������
class TaskQueue
{
public:
    // �������
    void put(const int& task)
    {
        lock_guard<mutex> locker(myMutex);
        while (taskQueue.size() == maxSize)
        {
            notFull.wait(myMutex);
        }
        taskQueue.push(task);
        cout << "�������: " << task << ", �߳�ID: " << this_thread::get_id() << endl;
        // ����������
        notEmpty.notify_one();
    }

    // ȡ����
    void take()
    {
        myMutex.lock();
        notEmpty.wait(myMutex, [=]() {
            return !taskQueue.empty();
            });

        int node = taskQueue.front();
        taskQueue.pop();
        cout << "ɾ������: " << node << ", �߳�ID: " << this_thread::get_id() << endl;
        myMutex.unlock();
        // ����������
        notFull.notify_all();
    }

    bool isFull()
    {
        lock_guard<mutex> locker(myMutex);
        if (maxSize == taskQueue.size())
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        lock_guard<mutex> locker(myMutex);
        if (taskQueue.size() == 0)
        {
            return true;
        }
        return false;
    }

    int taskSize()
    {
        lock_guard<mutex> locker(myMutex);
        return taskQueue.size();
    }
private:
    int maxSize = 100;
    queue<int> taskQueue;
    mutex myMutex;
    condition_variable_any notFull;     // ������
    condition_variable_any notEmpty;    // ������
};
#endif

int main()
{
    thread t1[10];
    thread t2[2];
    TaskQueue taskQ;
    for (int i = 0; i < 10; ++i)
    {
        t1[i] = thread(&TaskQueue::put, &taskQ, 100+i);
    }

        for (int i = 0; i < 2; ++i)
    {
        t2[i] = thread(&TaskQueue::take, &taskQ);
    }

    for (int i = 0; i < 10; ++i)    {t1[i].join();}
    for (int i = 0; i < 2; ++i)     {t2[i].join();}

    return 0;
}

#endif