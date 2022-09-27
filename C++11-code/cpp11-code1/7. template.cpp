#include <iostream>
using namespace std;

#if 0
// 1. 类模板的默认参数
// 默认参数位置有要求, 从右向左
template <typename T = int, T t = 520>
class Test
{
public:
    void print()
    {
        cout << "current value: " << t << endl;
    }
};

void classTemplateTest()
{
    Test<> t;
    t.print();

    Test<char, 'a'> t1;
    t1.print();
}

// 2. 函数模板的默认参数
// 2.1 例1 - 添加默认参数
template <typename T = int>
void func(T t)
{
    cout << "current value: " << t << endl;
}

// 2.2 例2 -- 默认参数位置无要求
template <typename R = int, typename N>
R func1(N arg)
{
    cout << "arg的类型" << typeid(arg).name() <<endl;
    return arg;
}

void func1Test()
{
    auto ret1 = func1(520);
    cout << "ret1的类型" << typeid(ret1).name() << endl;
    cout << "return value-1: " << ret1 << endl;

    auto ret2 = func1<double>(52.13f);
    cout << "ret2的类型" << typeid(ret2).name() << endl;
    cout << "return value-2: " << ret2 << endl;

    auto ret3 = func1<float>(52.13);
    cout << "ret3的类型" << typeid(ret3).name() << endl;
    cout << "return value-3: " << ret3 << endl;

    auto ret4 = func1<char, int>(100);
    cout << "ret4的类型" << typeid(ret4).name() << endl;
    cout << "return value-4: " << ret4 << endl;
}

// 2.3 例3
template <typename T, typename U = char>
// 函数的默认参数不能进行类型推导
// 推导: 1. 实参的类型 2. 默认类型
void func2(T arg1 = 100, U arg2 = 100)
{
    cout << "arg1: " << arg1 << ", arg2: " << arg2 << endl;
}
void func2Test()
{
    func2('a', 100);
    func2(97, 3.14);
    //func2();
}

int main()
{
    func2Test();
    return 0;
}

#endif


