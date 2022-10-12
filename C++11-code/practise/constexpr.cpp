#include <iostream>

struct Person
{
    std::string name;
    int age;
};

template <typename T>
constexpr T test(T t)
{
    return t;
}

void func1()
{
    Person p {"Tom",18};
    Person p_temp = test<Person>(p);

    std::cout<<p_temp.name<<"\t"<<p_temp.age<<std::endl;
}


constexpr int func2()
{
    using mytype = int;
    constexpr mytype a = 100;
    constexpr mytype b = 10;
    constexpr mytype c = a * b;
    return c - (a + b);
}

int main()
{
    
    const int a = 10;
    const int b = a;                //const
    constexpr int c = a;            //constexpr      

    func1();
    std::cout<<func2()<<std::endl;

    return 0;
}