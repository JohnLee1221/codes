#include <iostream>

struct A
{
    int num;
    std::string str;
};

struct B
{
    A a;
    int age;
};



void test(B::A t)
{

std::cout<<"test"<<std::endl;
}

int main()
{
    B b;
    test(b);

    return 0;
}