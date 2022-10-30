#include <iostream>
using namespace std;

#if 1
class Test
{
public:
    Test (int a){cout<<"construct the Test , value is : "<<a<<endl;}

    Test (const Test &t)
    {
        cout<<"test"<<endl;
    }
};

Test func(int num)
{
    return {num};                   //直接返回了一个匿名对象
}

Test func2()
{
    Test t(333);
    return t;
}

int main()
{
    Test t1(1);                   //普通构造
    Test t2 = 2;                  
    Test t5 = t1;                   //拷贝构造

    //列表初始化
    Test t3 = { 3 };
    Test t4{ 4 };
    Test t6 = func(100);
    Test t7 = func2();

    int a1 = { 1314 };
    int a2{ 1314 };
    int arr1[] = { 1, 2, 3 };
    int arr2[]{ 1, 2, 3 };
	



	std::initializer_list<int> init_list{1,2,3,4,5};
	cout<<init_list.size()<<endl;
	for(auto it = init_list.begin();it != init_list.end();it ++)
	{
		cout<<*it<<endl;
	}

    return 0;
}

#elif 0
class Person {
public:
	Person() {
		cout << "无参构造函数!" << endl;
		mAge = 0;
	}
	Person(int age) {
		cout << "有参构造函数!" << endl;
		mAge = age;
	}
	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
		mAge = p.mAge;
	}
	//析构函数在释放内存之前调用
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int mAge;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01() {

	Person man(100); //p对象已经创建完毕
	Person newman(man); //调用拷贝构造函数
	Person newman2 = man; //拷贝构造

	//Person newman3;
	//newman3 = man; //不是调用拷贝构造函数，赋值操作
}

//2. 值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person p1) {}
void test02() {
	Person p; //无参构造函数
	doWork(p);
}

//3. 以值方式返回局部对象
Person doWork2()
{
	Person p1;
	cout << (int *)&p1 << endl;
	return p1;
}

void test03()
{
	Person p = doWork2();
	cout << (int *)&p << endl;
}


int main() {

	test01();
	test02();
	test03();

	return 0;
}
#endif