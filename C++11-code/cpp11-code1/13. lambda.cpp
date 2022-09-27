#include <iostream>
#include <functional>
#include <vector>
using namespace std;

#if 0

#if 0
// 1. lambda 表达式
class Test
{
public:
    void output(int x, int y)
    {
        [] {return x + y};
        [] {return m_number; };                     
        [=] {return m_number + x + y; };            
        [&] {return m_number + x + y; };            
        [this] {return m_number; };                 
        [this] {return m_number + x + y; };         
        [this, x, y] {return m_number + x + y; };   
        [this] {return m_number++; };           
    }
    int m_number = 100;
};

void lambdaTest1()
{
    int a = 10, b = 20;
    [] {return a; };        
    [&] {return a++; }; 
    [=] {return a; }; 
    [=] {return a++; };
    [a] {return a + b; }; 
    [a, &b] {return a + (a++); };
    [=, &b] {return a + (b++); };
}
#endif

// 2. 修改拷贝到lambda表达式内部的常量
void modifyLambdaConstValue()
{
    int num = 9;
    // 匿名函数的定义, 如果要调用需要指定实参
    [=](int n) mutable {
        num++;
        cout << num << endl;
    }(7);
    cout << num << endl;
}

// 3. lambda表达式返回值
void lambdaReturnValue()
{
    // 完整的lambda表达式定义
    auto f = [](int a) -> int
    {
        return a + 10;
    };

    // 忽略返回值的lambda表达式定义, 自动推导返回值类型
    auto f1 = [](int a)
    {
        return a + 10;
    };
#if 0
    // error，不能推导出返回值类型
#if 0
    vector<int> v{1,2};
    int arr[]{ 1,2 };
    struct P
    {
        int a;
        int b;
    };
    P p1{ 1,2 };
#endif
    auto f2 = []()
    {
        return { 1, 2 };	// 基于列表初始化推导返回值，错误
    }
#endif
}

// 4. 包装和绑定 lambda 表达式
void packageLambda()
{
    using funcPtr1 = void(*)(int);
    funcPtr1 fptr = [=](int a) {
        cout << "没有引用外部数据" << endl;
    };

    int number = 100;
    // 捕获了外部数据
    auto f = bind([=](int a) {
        cout << number << endl;
    }, placeholders::_1);

    function<void(int)> f1 = [=](int a) {
        cout << number << endl;
        };

    function<void(int)> f2 = bind([=](int a) {
        cout << number << endl;
        }, placeholders::_1);

    // 没有引用外部数据
    funcPtr1 fptr = [](int a) {
        cout << "没有引用外部数据" << endl;
    };
    fptr(2);
}

int aaa()
{
    // part1
    function<void(T1, T2)> f1 = [](t1, t2) {
        for (auto i : t1)
        {
            for (auto i : t2)
            {
                xxxxxxx
                    xxxxxx
            }
        }
    };
    f1(x,x);
    f2(3,3);

}

int main()
{
    modifyLambdaConstValue();
	return 0;
}

#endif