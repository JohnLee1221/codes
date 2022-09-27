#include <iostream>
#include <thread>
#include <chrono>

class Person
{
public:
    Person(std::string name = "Null",int age = 0) : m_name(name),m_age(age){}

    void Person_msg()
    {
        std::cout<<"name : "<<m_name<<"\t"<<"age : "<<m_age<<std::endl;
    }

    static void Static_msg();

private:
    std::string m_name;
    int m_age;
    static int m_num;
};

int Person::m_num = 666;
void Person::Static_msg()
{
    std::cout<<"*******\t"<<m_num<<std::endl;
}


void func()
{
    std::cout<<"Hello World"<<std::endl;
}

int main()
{
    // std::cout<<std::this_thread::get_id()<<std::endl;

    std::thread t0(func);

    Person p1("Tom",18);
    std::thread t1(&Person::Person_msg,p1);

    std::thread t2(&Person::Static_msg);


    t0.join();
    t1.join();
    t2.join();

    return 0;
}