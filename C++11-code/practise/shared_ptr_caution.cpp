#include <iostream>
#include <memory>

class Person : public std::enable_shared_from_this<Person>
{
public:
    //std::shared_ptr<Person> func()
    //{
    //    return std::shared_ptr<Person>(this);
    //}

    std::shared_ptr<Person> func2()
    {
        return shared_from_this();
    }
};

void test()
{
    int *p = new int(100);
    std::shared_ptr<int> ptr1(p);
    //std::shared_ptr<int> ptr2(p);       //error
}

int main()
{
    std::shared_ptr<Person> ptr1{new Person()};
    //std::shared_ptr<Person> ptr2 = ptr1->func();
    std::shared_ptr<Person> ptr3 = ptr1->shared_from_this();
    //test();
}