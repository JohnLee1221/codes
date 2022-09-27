#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

#if 0
struct Person
{
    int age;
    string name;
};
Person* g_person;
once_flag g_flag;
void do_once(int a, string b)
{
    g_person = new Person{a, b};
    cout << "name: " << g_person->name 
        << ", age: " << g_person->age << endl;
}

void do_something(int age, string name)
{
    static int num = 1;
    call_once(g_flag, do_once, 19, "luffy");
    cout << "do_something() function num = " << num++ << endl;
}

int main()
{
    thread t1(do_something, 20, "ace");
    thread t2(do_something, 20, "sabo");
    thread t3(do_something, 19, "luffy");
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
#endif