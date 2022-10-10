#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
    Test(int a,int b,string c) : m_a(a),m_b(b),m_c(c) {}               //初始化列表

public:
    int m_a ;
    int m_b = 10;                     //通过=，对成员变量初始化
    string m_c = "Hello";           //通过{}，对成员变量初始化

    const static int num1 = 0;       //如果静态变量是静态常量，且类型是整形或者枚举类型，可以在类内初始化

    //static int num2 = 10;
    static int num2;                //类内声明，类外初始化
};

int Test::num2 = 10;

int main()
{
    vector<int> a{1,2,3,4,5};
    vector<int> b(1,2,3,4,5);

    Test test{1,3,"world"};
    cout<<test.m_c<<endl;

    return 0;
}