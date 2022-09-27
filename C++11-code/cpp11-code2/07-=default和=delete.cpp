#include <iostream>
using namespace std;

#if 0
class Test
{
public:
    Test() = default;
    ~Test() = default;
    Test(const Test& t) = default;
    Test(Test&& t) = default;
    Test& operator=(const Test& t) = default;
    Test& operator=(Test&& t) = default;
    Test() {}
};

class Test1
{
public:
    Test1();
    Test1(const Test1& t) = delete;
    Test1& operator=(const Test1& t) = delete;
    //void print() = default;
    void print(int num)
    {
        cout << num << endl;
    }
    void print(char c) = delete;
};
Test1::Test1() = default;

int main()
{
    Test1 t;
    t.print(100);
    t.print('a');
    //Test1 tt(t);
    //Test1 t2 = t;
    //t2 = t;
    return 0;
}
#endif