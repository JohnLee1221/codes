#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>
using namespace std;
#if 0

#if 0
// 任务队列类
class TaskQueue
{
public:
    // 添加数据
    void put(const int& task)
    {
        unique_lock<mutex> locker(myMutex);
        while (taskQueue.size() == maxSize)
        {
            notFull.wait(locker);
        }
        taskQueue.push(task);
        cout << "添加任务: " << task << ", 线程ID: " << this_thread::get_id() << endl;
        // 唤醒消费者
        notEmpty.notify_one();
    }

    // 取数据
    void take()
    {
        unique_lock<mutex> locker(myMutex);
        while (taskQueue.empty())
        {
            notEmpty.wait(locker);
        }

        int node = taskQueue.front();
        taskQueue.pop();
        cout << "删除任务: " << node << ", 线程ID: " << this_thread::get_id() << endl;
        // 唤醒生产者
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
    condition_variable notFull;     // 生产者
    condition_variable notEmpty;    // 消费者
};
#else
// 任务队列类
class TaskQueue
{
public:
    // 添加数据
    void put(const int& task)
    {
        lock_guard<mutex> locker(myMutex);
        while (taskQueue.size() == maxSize)
        {
            notFull.wait(myMutex);
        }
        taskQueue.push(task);
        cout << "添加任务: " << task << ", 线程ID: " << this_thread::get_id() << endl;
        // 唤醒消费者
        notEmpty.notify_one();
    }

    // 取数据
    void take()
    {
        myMutex.lock();
        notEmpty.wait(myMutex, [=]() {
            return !taskQueue.empty();
            });

        int node = taskQueue.front();
        taskQueue.pop();
        cout << "删除任务: " << node << ", 线程ID: " << this_thread::get_id() << endl;
        myMutex.unlock();
        // 唤醒生产者
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
    condition_variable_any notFull;     // 生产者
    condition_variable_any notEmpty;    // 消费者
};
#endif

int main12345678()
{
    thread t1[5];
    thread t2[5];
    TaskQueue taskQ;
    for (int i = 0; i < 5; ++i)
    {
        t1[i] = thread(&TaskQueue::put, &taskQ, 100+i);
        t2[i] = thread(&TaskQueue::take, &taskQ);
    }

    for (int i = 0; i < 5; ++i)
    {
        t1[i].join();
        t2[i].join();
    }
    return 0;
}

#endif