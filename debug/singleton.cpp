#include <iostream>

// class Person
// {
// public:
//     static Person& setInstance(){return p;}

//     void setup()
//     {
//         std::cout<<"hello"<<std::endl;
//     }
// private:
//     Person() = default;
//     Person(const Person &p) = default;

//     static Person p;
//     static int a;
// };
// Person Person::p;

class Person
{
public:
    static Person& setInstance();
    void setup(){std::cout<<"lalala"<<std::endl;}
private:
    Person() = default;
    Person(const Person &p) = default;
};

Person& Person::setInstance()
{
    static Person p;
    return p;
}

int main()
{
    Person::setInstance().setup();

    return 0;
}