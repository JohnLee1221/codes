#include <iostream>
using namespace std;

using Ptr = void (*)(string);

auto auto_Ptr = [](string str){};

class Person
{
public:
    Person(string name = "NULL"): m_name(name)
    {
        cout<<m_name<<endl;
    }

    //void operator() (string name)
    //{
    //    m_name = name;
    //    cout<<"operator(): "<<m_name<<endl;
    //} 
public:
    string m_name;
};

int main()
{
    Person p("Tom");
    Person p1;
    //p("Hello");

    return 0;
}