#include <iostream>
#include <functional>
using namespace std;

#if 1
// 1. 可调用对象
// 1.1 函数指针
using funcPtr1 = int(*)(int, double);
int print(int a, double b)
{
    cout << a << b << endl;
    return 0;
}

// 1.2 仿函数
struct Test
{
    // ()操作符重载
    void operator()(string msg)
    {
        cout << "msg: " << msg << endl;
    }
};
void test1()
{
    Test t;
    t("hello");
}

// 1.3 是一个可被转换为函数指针的类对象
using func_ptr = void(*)(int, string);
struct Test1
{
    static void print(int a, string b)
    {
        cout << "name: " << b << ", age: " << a << endl;
    }

    // 将类对象转换为函数指针
    operator func_ptr()
    {
        return print;
    }
};

// 1.4 是一个类成员函数指针或者类成员指针
struct Test2
{
    void print(int a, string b)
    {
        cout << "name: " << b << ", age: " << a << endl;
    }
    static int hello(string msg)
    {
        cout << "Test static function hello: " << msg;
        return 0;
    }
    int m_num;
};

void callObjectTest()
{
    Test2 t;
    void (Test2:: * func_ptr)(int, string) = Test2::print;
    (t.*func_ptr)(1, "tom");

    int Test2::* intPtr = &Test2::m_num;
    t.*intPtr = 99;
}

// 2. 可调用对象包装器 - function
void functionTest()
{
    // 函数指针
    function<int(int, double)> f1 = print;
    // 仿函数
    Test t;
    function<void(string)> f2 = t;
    // 对象转换为函数指针
    Test1 t1;
    function<void(int, string)> f3 = t1;
    // 类的静态函数
    function<int(string)> f4 = Test2::hello;

    // 调用
    f1(1, 3.14);
    f2("hello,world");
    f3(2, "tom");
    f4("我是 f4 function");
}

// 3. function 应用场景举例
// 回调函数: 函数的调用是有操作系统或者框架完成的
// 程序要只需要实现这个函数就好了
// 特定的时机被框架(或系统调用)

class A
{
public:
    // 构造函数参数是一个包装器对象
    A(const function<void()>& f) : callback(f)
    {
    }
    void notify()
    {
        // 调用通过构造函数得到的函数指针
        callback(); 
    }

private:
    function<void()> callback;
};

class B
{
public:
    void operator()()
    {
        cout << "我是要成为海贼王的男人!!!" << endl;
    }
};

void functionTest1()
{
}

// 4. 可调用对象绑定器 bind
void output(int x, int y)
{
    cout << x << " " << y << endl;
}
void bindTest(void)
{
    // 语法: auto f = std::bind(可调用对象地址, 绑定的参数/占位符);
    // 使用绑定器绑定可调用对象和参数, 并调用得到的仿函数
    auto f1 = bind(output, 1, 2);
    auto f2 = bind(output, placeholders::_1, placeholders::_2);
    auto f3 = bind(output, 2, placeholders::_1);
    f3(5);

    // error, 调用时没有第二个参数
    // bind(output, 2, placeholders::_2)(10);
    bind(output, 2, placeholders::_2)(10, 20);

    bind(output, placeholders::_1, placeholders::_2)(10, 20);
    auto fff = bind(output, placeholders::_2, placeholders::_1);
    fff(4, 5);


    // 如果只绑定不调用呢?
}

// 5. 绑定类的成员函数或者类的成员变量
class Test3
{
public:
    void output(int x, int y)
    {
        cout << "x: " << x << ", y: " << y << endl;
    }
    int m_number = 100;
};

void bindClassMember()
{
    Test3 t;
    // 语法: std::bind(类函数/成员地址, 类实例对象地址, 绑定的参数/占位符);
    // 绑定类成员函数
    auto f1 = bind(&Test3::output, &t, 
        placeholders::_1, placeholders::_2);

    function<void(int, int)> f3 = bind(&Test3::output, &t,
        placeholders::_1, placeholders::_2);

    // 绑定类的成员变量
    auto f2 = bind(&Test3::m_number, &t);
    f2() = 9;
    cout << f2() << endl;

    function<int&(void)> f4 = bind(&Test3::m_number, &t);
    f4() = 9;
    cout << f4() << endl;

    f1(3, 4);
    f2();
}


int main()
{
    functionTest();
	return 0;
}
#elif 0
#endif