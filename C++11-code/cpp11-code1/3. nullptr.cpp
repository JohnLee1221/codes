#include <iostream>
using namespace std;

#if 0
void func(const char* p)
{
    cout << "void func(char *p)" << endl;
}

void func(int p)
{
    cout << "void func(int p)" << endl;
}

int main()
{
    // nullptr  是值
    // nullptr 对应的类型: nullptr_t
    const char* str = "hello";
    func(nullptr);
    func(250);

    return 0;
}
#endif