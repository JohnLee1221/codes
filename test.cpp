#include<iostream>
#include<limits>
using namespace std;

class Person
{
public:
    Person(int a)
    {
        cout<<"construct function"<<"\t"<<a<<endl;
    }

    Person* test()
    {
        return this;
    }
};

int main()
{
    Person p = Person(100);
    Person(10).test();

    return 0;
}