#include <iostream>
// #include <cassert>
using namespace std;

#if 0
char* createArray(int size)
{
    assert(size > 0);
    char* array = new char[size];
    return array;
}
int main()
{
    // char* buf = createArray(10);
    static_assert(sizeof(long) == 8, "��ǰ����ϵͳ����64λ");
    cout << "hello, world" << endl;

    return 0;
}
#endif
