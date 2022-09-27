#include <iostream>
using namespace std;

#if 0
// 1. move 的使用
class Test
{
public:
	Test() : m_i(new int(2)) { cout << "Test clsss construct..." << endl; }
	Test(Test&& t):m_i(t.m_i) 
	{ 
		t.m_i = nullptr;
		cout << "Move construct..." << endl; 
	};
	~Test() 
	{
		delete m_i;
		cout << "Test class destruct..." << endl;
	}
// private:
	int* m_i;
};

void moveTest()
{
	// 1. 给右值引用赋值
	Test t;
	// 2. 实例化类对象
	Test tt(move(t));
	cout << "t.m_i = " << t.m_i << endl;
}

// 2. move 的应用(通过临时对象构造新的对象)
class Base
{
public:
	Base(int size) : m_sz(size > 0 ? size : 1)
	{
		m_array = new int[size];
		cout << "Base class construct..." << endl;
	}
	Base(Base&& b) :m_sz(b.m_sz), m_array(b.m_array)
	{
		m_array = nullptr;
		cout << "Base class move construct..." << endl;
	}
	~Base()
	{
		delete[]m_array;
		cout << "Base class destruct..." << endl;
	}
	// 为了方便测试, 故将成员变量访问权限设置为public
	int* m_array;
	int m_sz;
};

class Moveable
{
public:
	Moveable() : m_num(new int(3)), m_base(128)
	{
		cout << "Moveable class construct..." << endl;
	}
	// 移动构造函数
	Moveable(Moveable&& m) :m_num(m.m_num), m_base(move(m.m_base))
	{
		m_num = nullptr;
		cout << "Moveable class move construct..." << endl;
	}
	~Moveable()
	{
		delete m_num;
		cout << "Moveable class destruct..." << endl;
	}

    // 为了方便测试, 故将成员变量访问权限设置为public
    int* m_num;
	Base m_base;
};

// 需求: 通过 Moveable 的临时对象构造一个新的 Moveable 对象
Moveable getTemp()
{
	Moveable tmp = Moveable();
	return tmp;
}

void testPoint()
{
	// 关于堆内存和栈内存
    int arr[] = { 11,2,2 };
    int* p = arr;
    int* array = new int[3];
    int* pt = array;
    delete[]array;

    int* array1 = (int*)malloc(sizeof(int) * 16);
    free(array1);
}

// 3. 完美转发 - forward
template<typename T>
void printValue(T& t)
{
    cout << "l-value: " << t << endl;
}

template<typename T>
void printValue(T&& t)
{
    cout << "r-value: " << t << endl;
}

template<typename T>
void testForward(T&& v) // 右值引用
{
    printValue(v);	// l-value
    printValue(move(v));	// r-value
    printValue(forward<T>(v));
    cout << endl;
}

void forwardTest()
{
    testForward(520);
    int num = 1314;
    testForward(num);
    testForward(forward<int>(num));
    testForward(forward<int&>(num));
    testForward(forward<int&&>(num));
}

int main()
{
	forwardTest();
	return 0;
}
#endif