#include <iostream>
#include <vector> // 顺序容器(动态数组)
#include <list>     // 各元素内存不连续
#include <map>
using namespace std;

#if 0

#if 0
// 1. 使用auto进行类型推导
void autoTest1()
{
    auto x = 3.14;
    auto y = 520;
    auto z = 'a';
    auto nb; 
    auto  nbl = "ssss";
    int ii = 9, jj = 88;
    auto i = 1, j = 3;

    // auto的推导规则
    int temp = 110;
    auto* a = &temp;  // int * ==> auto (int)
    auto b = &temp;  // int*  ==> auto(int*)
    auto& c = temp;    // int& ==> auto(int)
    auto d = temp; // int
    // 带 const 限定
    int tmp = 250;
    const auto a1 = tmp; // const int ==> auto (int)
    auto a2 = a1;   // auto (int)
    const auto& a3 = tmp; // const int& ==> auot(int)
    auto& a4 = a3; // const int& ==> auto(const int)
}
#endif

#if 0
// 2. auto 的限制
class Test
{
public:
    void print(auto i)
    {
        cout << i << endl;
        int array[] = { 1,2,3,4,5 }; 
        auto t1 = array; // int*
        auto t2[] = array; 
        auto t3[] = { 1,2,3,4,5 };
    }
private:
    int num = 9;
    auto id = 8;
    static int num1;
    static constexpr auto number = 10;
};

template <typename T>
struct Test {};

int func()
{
    Test<double> t;
    Test<auto> t1 = t;

    vector<int> v = { 1,2,3,4,5 };
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}
#endif

// 3-1. auto的应用 --> 遍历容器
void traverseMap()
{
    // key必须是唯一的
    map<string, string> mp;
    // std::pair p; 对组 
    // 第一个值 key: p.first , value值: p.second
    mp.insert(make_pair("Beijing", "China"));
    mp.insert(make_pair("Tokyo", "Japan"));
    mp.insert(make_pair("Paris", "France"));
    mp.insert(make_pair("London", "Britain"));
    mp.insert(make_pair("Washington", "America"));
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        // 迭代器类型的变量可以看做是一个指针
        cout << "key: " << it->first 
            << ", valfue: " << it->second << endl;
    }
}

// 3-2. auto的应用 --> 泛型编程
class T1
{
public:
    static int get()
    {
        return 10;
    }
};

class T2
{
public:
    static string get()
    {
        return "hello, world";
    }
};
// 编写一个函数模板, 处理T1, T2类中的静态方法调用
template<typename T>
void get11()
{
    auto ret = T::get();
    cout << "ret value: " << ret << endl;
}


// 4. decltype 测试
class Test
{
public:
    int num = 9;
    string text;
    static const int value = 110;
};

//函数声明
int func_int() { return 0; };                 // 返回值为 int
int& func_int_r() { int a; return a; };       // 返回值为 int&
int&& func_int_rr() { return 1; };            // 返回值为 int&&

const int func_cint() { return 1; };          // 返回值为 const int
const int& func_cint_r() { int a; return a; };// 返回值为 const int&
const int&& func_cint_rr() { return 1; };     // 返回值为 const int&&


const Test func_ctest() { return Test(); };   // 返回值为 const Test

void decltypeTest()
{
    int a = 10;
    decltype(a) b = 99;
    decltype(a + 3.14f) c = 52.13f;
    decltype(a + 1.2 * c) d = 520.1314;

    // 规则1
    int x = 99;
    const int& y = x;
    decltype(x) a1 = x;
    decltype(y) b1 = x;
    decltype(Test::value) c1 = 0;

    Test t;
    decltype(t.text) d1 = "hello, world";

    // 规则2
    int n = 100;
    decltype(func_int()) a2 = 0;
    decltype(func_int_r()) b2 = n;
    decltype(func_int_rr()) c2 = 0;

    decltype(func_cint())  d2 = 0;
    decltype(func_cint_r())  e2 = n;
    decltype(func_cint_rr()) f2 = 0;
    // 和 d2 不同
    decltype(func_ctest()) g2 = Test();  

    // 规则3
    const Test obj;
    //带有括号的表达式
    decltype(obj.num) a3 = 0;
    decltype((obj.num)) b3 = a3;
    //加法表达式
    int n3 = 0, m3 = 0;
    decltype(n3 + m3) c3 = 0;
    decltype(n3 = n3 + m3) d3 = n3;
}

#if 1
// 5. decltype 的应用
template <typename T>
class Container
{
public:
    void func(T& c)
    {
        for (m_it = c.begin(); m_it != c.end(); ++m_it)
        {
            cout << *m_it << " ";
        }
        cout << endl;
    }
private:
    decltype(T().begin()) m_it;  // 这里不能确定迭代器类型
};
#endif

// 6. 追踪返回值类型(返回值类型后置)
// 6-1.求两个数之和
template <typename R, typename T, typename U>
R sum(T t, U u)
{
    return t + u;
}

template <typename T, typename U>
auto sum(T t, U u) -> decltype(t + u)
{
    return t + u;
}

void returnTypeTest1()
{
    auto ret = sum(1, 'a');
    cout << "ret: " << ret << endl;
}

// 6-2. 例2 -> 根据以下两个函数写一个函数模板
int& test(int& i)
{
    return i;
}
double test(double& d)
{
    d = d + 100;
    return d;
}

template <typename T>
auto MyTest(T& t) -> decltype(test(t))
{
    return test(t);
}


int main()
{
    get11<T1>();
    get11<T2>();

    vector<int> v = {1,2,3,4,5};
    list<int> ll = { 11,22,33,44,55 };

    Container<vector<int>> c;
    c.func(v);

    Container<list<int>> c1;
    c1.func(ll);

    returnTypeTest1();

	return 0;
}

#endif