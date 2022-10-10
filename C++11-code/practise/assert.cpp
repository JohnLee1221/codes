#include <iostream>
#include <cassert>
using namespace std;

void func1()
{
    int a;
    cin >> a;

    assert(a > 5);
    cout<<"assert func1"<<endl;
}

void func2()
{
    int a = 10;
    
    static_assert(a > 5,"Error");
    cout<<"static_assert func2"<<endl;
}

int main()
{
    //func1();
    func2();

    return 0;
}