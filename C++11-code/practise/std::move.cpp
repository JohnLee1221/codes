#include <iostream>
using namespace std;

class Person
{
public:
    Person(string name,int age): m_name(name),m_age(age){}

public:
    string m_name;
    int m_age;
};

Person func()
{
    return Person("Tom",18);
}

int main()
{
    Person p1{"Jerry",20};
    Person p2 = p1;

    //Person && p3 = p1;
    Person && p3 = func();
    //Person && p4 = p3;                  //右值引用，p3本身是一个左值
    Person && p4 = std::move(p2);

    cout<<p2.m_name<<"\t"<<p2.m_age<<endl;
    cout<<p3.m_name<<"\t"<<p3.m_age<<endl;
    p2.m_name = "lalala";
    cout<<p4.m_name<<"\t"<<p4.m_age<<endl;
    cout<<p2.m_name<<"\t"<<p2.m_age<<endl;

    return 0;
}