#include <iostream>
using namespace std;

struct Msg
{
    Msg(string str) : msg(str){}
    string msg;
};

void func() noexcept
{
    throw Msg("Hello world");
}

int main()
{
    try { func(); }

    catch (Msg msg)
    {
        cout<<"success"<<endl;
    }

    return 0;
}
