#include <iostream>
using namespace std;

#if 0
struct Base { static int a; };
struct Child : public Base { 
    int b; 
    Base bb;
};  // pod����

struct Base1 { 
public:
    int a;
private:
    void print() {}
};
struct Child1 : public Base1 { static int c; };  // pod ����

// base: ��̬
// base1: �Ǿ�̬
// child2: ��̬
struct Child2 :public Base, public Base1 { static int d; }; // pod ����

struct Child3 :public Base1 { int d; }; // ����pod ����
// base1: �Ǿ�̬
// child: �Ǿ�̬
// child4: ��̬
struct Child4 :public Base1, public Child // ����pod����
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
    cout << "Test �ǲ���ƽ�����͵�POD? " << is_trivial<Test>::value << endl;

    cout << "��׼�������͵��ж�: " << is_standard_layout<Base1>::value << endl;
    cout << "��׼�������͵��ж�: " << is_standard_layout<Child4>::value << endl;
    return 0;

}
#endif