#include <iostream>
#include <map>
using namespace std;

#if 0
double hello(int i, double d)
{
	return i + d;
}

// 1. 定义别名 -> 等价于 typedef
// 一般数据类型
typedef unsigned int uint_t;
using uint_tt = unsigned int;

// 函数指针
double aaaa(int a, double b)
{
}

typedef double(*func_ptr)(int, double);
using funcPtr = double(*)(int, double);

void aa()
{
	func_ptr fptr = aaaa;
	funcPtr fptr1 = aaaa;
	fptr(1, 1.1);
}


// 2. 定义模板的别名 - typedef 无法直接实现
// 请将以下三种类型的映射统一封装到一个模板中(key类型相同, value类型不同)
typedef map<int, string> m1;
typedef map<int, int> m2;
typedef map<int, double> m3;

// 使用typedef
#if 0
template<typename T>
typedef map<int, T> type;
#else
template<typename T>
struct MyMap
{
	typedef map<int, T> type;
};
#endif
void test11()
{
	MyMap<string>::type m1;
	m1.insert(make_pair(1, "tom"));
	m1.insert(make_pair(2, "jack"));

    MyMap<int>::type m2;
    m2.insert(make_pair(1, 11));
    m2.insert(make_pair(2, 22));
}

// 使用using给模板定义别名
template<typename T>
using MyMap1 = map<int, T>;
void test12()
{
	MyMap1<string> m1;
    m1.insert(make_pair(1, "tom"));
    m1.insert(make_pair(2, "jack"));

	MyMap1<int> m2;
    m2.insert(make_pair(1, 11));
    m2.insert(make_pair(2, 22));
}

int main()
{
	
	return 0;
}
#endif