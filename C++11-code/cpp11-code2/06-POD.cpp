#include <iostream>
using namespace std;

#if 0
struct Base { static int a; };
struct Child : public Base { 
    int b; 
    Base bb;
};  // pod类型

struct Base1 { 
public:
    int a;
private:
    void print() {}
};
struct Child1 : public Base1 { static int c; };  // pod 类型

// base: 静态
// base1: 非静态
// child2: 静态
struct Child2 :public Base, public Base1 { static int d; }; // pod 类型

struct Child3 :public Base1 { int d; }; // 不是pod 类型
// base1: 非静态
// child: 非静态
// child4: 静态
struct Child4 :public Base1, public Child // 不是pod类型
{
    static int num;
};

class Test
{
public:
    Test() = default;
    Test(int a) {}

    static int val;
    static char* buf;
};
int Test::val = 100;
char* Test::buf = new char[100];

int main()
{
    cout << "Test 是不是平凡类型的POD? " << is_trivial<Test>::value << endl;

    cout << "标准布局类型的判断: " << is_standard_layout<Base1>::value << endl;
    cout << "标准布局类型的判断: " << is_standard_layout<Child4>::value << endl;
    return 0;

}
#endif