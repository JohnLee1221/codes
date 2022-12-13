#include <iostream>
#include <vector>

class Person
{
public:
    Person() = default;
public:
    std::vector<int> v1_;
    int num_;
};

class Test
{
public:
    Test() = default;
public:
    std::vector<int> v2_;
    std::string str_;
};

void foo()
{
    Person p1;
    p1.num_ = 88;
    for(int i = 0;i < 10;i++)
    {
        p1.v1_.push_back(i);
    }

    Test t1;
    t1.v2_ = p1.v1_;

    std::cout<<p1.num_<<std::endl;
    std::cout<<p1.v1_.size()<<std::endl;

    std::cout<<t1.v2_.size()<<std::endl;
}

int main()
{
    foo();

    return 0;
}
