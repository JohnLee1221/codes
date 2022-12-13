#include <iostream>
using namespace std;

class T1
{
public:
    static int get() {return 10;}
};

class T2
{
public:
    static string get() {return "hello, world";}
};

#if false
template <class A>
void func1(void)
{
    auto val = A::get();				//使用auto自动类型推导
    cout << "func1  val: " << val << endl;
}

int main()
{
    func1<T1>();
    func1<T2>();
    return 0;
}

#else
template <class A, typename B>        // 不使用auto，添加了模板参数 B
void func2(void)
{
    B val = A::get();
    cout << "func2  val: " << val << endl;
}

int main()
{
    func2<T1,int>();
    func2<T2,string>();
    return 0;
}
#endif