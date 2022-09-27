#include <iostream>
using namespace std;

#if 0
struct MyException
{
    MyException(string str) :msg(str) {}
    string msg;
};
void func() noexcept(true)
{
        // throw 1;
        //throw MyException("string exception!");
}
int main()
{
    try
    {
        func();
    }
    catch (MyException e)
    {
        cout << "hello, world!" << endl;
    }
    return 0;
}
#endif