#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
using namespace std;

#if 0
struct Base
{
    Base(int n, string s) :age(n), name(s) {}

    int age;
    string name;
};

class Counter
{
public:
    void increment()
    {
        for (int i = 0; i < 100; ++i)
        {
            //mtx.lock();
            number++;
            cout << "+++ increment thread id: " << this_thread::get_id() 
                << ", number: " << number << endl;
            //mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    void increment1()
    {
        for (int i = 0; i < 100; ++i)
        {
            //mtx.lock();
            number++;
            cout << "*** decrement thread id: " << this_thread::get_id()
                << ", number: " << number << endl;
            //mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
private:
    //int number = 0;
    atomic_int number = 0;
    atomic<Base*> base;
    //mutex mtx;
};


int main()
{
    Counter c;
    thread t1(&Counter::increment, &c);
    thread t2(&Counter::increment1, &c);

    t1.join();
    t2.join();
#if 0
    atomic<char> c('a');
    atomic_char cc('b');

    atomic<int> b;
    atomic_init(&b, 9);

    cc = 'd';
    b.store(88);

    char ccc = c.exchange('e');

    Base base(123, "luffy");
    atomic<Base*> atc_base(&base);

    cout << "c value: " << c << endl;
    cout << "ccc value: " << ccc << endl;
    cout << "b value: " << b.load() << endl;
    Base* tmp = atc_base.load();
    cout << "name: " << tmp->name << ", age: " << tmp->age << endl;

    b = 12;
#endif
    return 0;
}
#endif