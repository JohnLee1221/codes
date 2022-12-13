#include <iostream>

class Person
{
    friend Person operator+ (Person& p1,Person& p2);
    friend std::ostream& operator<< (std::ostream& out,Person&p);
public:
    Person() = default;

    Person(const Person& p)
    {
        this->age_ = p.age_;
        this->name_ = p.name_;
        std::cout<<"copy constructor"<<std::endl;
    }

    Person(std::string name,int age): name_(name),age_(age){}

    void printFunc()
    {
        std::cout<<this->name_<<"\t"<<this->age_<<std::endl;
    }

    Person& operator+ (const Person& p)
    {
        this->age_ += p.age_;
        return *this;
    }

    Person& operator= (const Person& p)
    {
        this->age_ = p.age_;
        this->name_ = p.name_;
        std::cout<<"operator = "<<std::endl;
        return *this;
    }

    bool operator< (const Person& p)
    {
       return this->age_ < p.age_ ? true : false;
    }

private:
    std::string name_;
    int age_;
};

Person operator+ (Person& p1,Person& p2)
{
    Person temp;
    temp.age_ = p1.age_ + p2.age_;
    temp.name_ = p2.name_;

    return temp;
}

std::ostream& operator<< (std::ostream& out,Person&p)
{
    out<<"name: "<<p.name_<<"\t"<<"age: "<<p.age_<<std::endl;
    return out;
}

void test()
{
    Person p1{"Tom",20};
    Person p2{"Jerry",18};
    p1.printFunc();
    p2.printFunc();

    // (p1+p2).printFunc();
    // (p2+p1).printFunc();

    Person p3 = p2;
    Person p4;
    p4 = p2;

    auto testPerson = p1 + p2;
    testPerson.printFunc();


    std::cout<<p4;

}

int main()
{
    test();

    return 0;
}