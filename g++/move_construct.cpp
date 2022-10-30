#include <iostream>
using namespace std;

class Person
{
public:
    Person(int &a): num(new int{a}){}
    Person(const Person &p) = default;

    Person(Person && p)
    {
        num = p.num;
        p.num = nullptr;

        cout<<"move construct function"<<endl;
    }

    ~Person()
    {
        delete num;
    }
public:
    int* num;
};

int main()
{
    int a = 1000;
    Person p1(a);

    Person p2{std::move(p1)};
    Person p3 = std::move(p2);

    return 0;
}