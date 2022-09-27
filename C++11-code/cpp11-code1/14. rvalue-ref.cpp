#include <iostream>
using namespace std;

#if 0
// 左值: 可以取地址的变量(表达式)
// 右值: 不能取地址是右值 5, 'a'
// 左值引用: 
// 右值引用:
int num = 9;
int& num1 = num;
int&& num2 = 9;

// 1. 右值引用的使用
#if 0
int&& value = 520;
class Test
{
public:
    Test()
    {
        cout << "construct: my name is jerry" << endl;
    }
    Test(const Test& a)
    {
        cout << "copy construct: my name is tom" << endl;
    }
};

Test getObj()
{
    return Test();
}

void test111()
{
    // 调用拷贝构造函数, 进行对象的拷贝
    Test t = getObj();
    // get()返回的对象是将亡值(就是右值的一种)
    // 匿名对象被销毁了, 但是它的内存被t1接管了
    Test&& t1 = getObj();
}


// 常量的左值引用是王能引用类型 可以引用:
//  左值, 右值, 常量左值, 常量右值
void rvalueRefTest()
{
    int&& a2 = a1; 
    Test& t = getObj();
    Test&& t1 = getObj();
    const Test& t2 = getObj();
}
#endif

// 2. 右值引用对性能的优化
#if 0
class Demo
{
public:
    Demo() : m_num(new int(100))
    {
        cout << "construct: my name is jerry" << endl;
    }

    Demo(const Demo& a) : m_num(new int(*a.m_num))
    {
        cout << "copy construct: my name is tom" << endl;
    }

    ~Demo()
    {
        delete m_num;
        cout << "destruct Test class ..." << endl;
    }

    int* m_num;
};
#else
class Demo
{
public:
    Demo() : m_num(new int(100))
    {
        cout << "construct: my name is jerry" << endl;
    }

    Demo(const Demo& a) : m_num(new int(*a.m_num))
    {
        cout << "copy construct: my name is tom" << endl;
    }

    // 添加移动构造函数
    Demo(Demo&& a) : m_num(a.m_num)
    {
        a.m_num = nullptr;
        cout << "move construct: my name is tom" << endl;
    }

    ~Demo()
    {
        delete m_num;
        cout << "destruct Test class ..." << endl;
    }

    int* m_num;
};
#endif

Demo getObject()
{
    Demo t;
    return t;
}

void rvalueRefTest2()
{
    Demo t = getObject();
    cout << "t.m_num: " << *t.m_num << endl;
}
#if 0
// 3. && 的推导
// 3.1 例1 -> 模板的类型推导
template<typename T>
void f(T&& param) {};

template<typename T>
// 右值引用
void f1(const T&& param) {};

void test1()
{
    f(10);  // 右值引用
    int x = 10;
    f(x);   // 左值引用
    f1(x);  // 语法错误
    f1(10); // ok
}

// 3.2 例2 -> 自动类型推导
void test2()
{
    int x = 520, y = 1314;
    auto&& v1 = x;
    auto&& v2 = 250;
    decltype(x) && v3 = y;   
    cout << "v1: " << v1 << ", v2: " << v2 << endl;

    int&& a1 = 5; 
    auto&& bb = a1;
    auto&& bb1 = 5;

    int a2 = 5;
    int& a3 = a2;
    auto&& cc = a3;
    auto&& cc1 = a2;

    const int& s1 = 100;
    const int&& s2 = 100;
    auto&& dd = s1;
    auto&& ee = s2;

    const auto&& x = 5;
}
#endif
#if 1

// 3.3 例3 -> 基于函数参数进行类型推导
void printValue(int& i)
{
    cout << "l-value: " << i << endl;
}

void printValue(int&& i)
{
    cout << "r-value: " << i << endl;
}

void forward(int&& k)
{
    // 被冠名的右值引用继续被使用, 会被视为一个左值
    printValue(k);
}

void test3()
{
    int i = 520;
    // l-value
    printValue(i);
    // r-value
    printValue(1314);
    // l-value
    forward(250);
};
#endif
int main()
{
    test3();
    return 0;
}
#endif