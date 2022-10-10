#include <iostream>
using namespace std;

void func(long * ptr)
{
    cout<<"pointer"<<endl;
}

// void func(void * ptr)
// {
//     cout<<"void"<<endl;
// }

void func(int num)
{
    cout<<"number"<<endl;
}

void NULL_test()
{
    cout<<"enter NULL_test function"<<endl;

    //c++中   #define NULL 0
    int * ptr1 = NULL;
    char * ptr2 = NULL;
    long * ptr3 = NULL;
    void * ptr4 = NULL;

    // int * ptr5 = ptr3;
    int * ptr6 = (int *)ptr3;
    
    func(1);

    //func(NULL);
    //NULL在c++中如果要作为参数调用函数，需要对其进行强制类型转换
    func((long *)NULL);
}

void nullptr_test()
{
    cout<<"enter nullptr_test function"<<endl;
    
    func(1);

    //nullptr可以自动的转换类型,但要排除可能的奇异性
    func(nullptr);
}

int main()
{
    NULL_test();
    nullptr_test();

    return 0;
}