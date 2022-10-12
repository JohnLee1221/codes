#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string test(int a)
{
    return "Hello World";
}

void foo1(int num,string (*ptr)(int))
{
    cout<<num<<"\t"<<ptr(num)<<endl;
}

void foo2(string (*ptr)(int))
{
    int num = 2;
    cout<<num<<"\t"<<ptr(num)<<endl;
}


void func1()
{
    foo1(1,test);
    foo2(test);
}

// void func2()
// {
//     void (*ptr1)(int) = test;

//     void (*ptr2)(int);
//     ptr2 = test;

//     typedef void(*Ptr)(int);
//     Ptr ptr3 = test;

//     using Ptr = void(*)(int);
//     Ptr ptr4 = test;

//     ptr1(1);
//     ptr2(2);
//     ptr3(3);
//     ptr4(4);
// }



int main()
{
    func1();

    return 0;
}

