#include <iostream>
#include <memory>
#include <functional>
using namespace std;

#if 0
unique_ptr<int> getPtr()
{
	unique_ptr<int> ptr1(new int(3));
	return ptr1;
}
// 1. unique_ptr 初始化
void uniquePtrInit()
{
	// 1. 通过构造函数
	unique_ptr<int> ptr1(new int(3));
	// 2. 通过转移所有权的方式
    unique_ptr<int> ptr2 = move(ptr1);
	unique_ptr<int> ptr3 = getPtr();
	// 3. 通过reset()函数
	unique_ptr<int> ptr4;
	ptr4.reset(new int(6));
	ptr4.reset();
}

// 2. unique_ptr 指定删除器
class Test
{
public:
    Test() { cout << "Test class construct..." << endl; }
    Test(int id, string name) { cout << "Test class construct..." << endl; }
    ~Test() { cout << "Test class destruct..." << endl; };
    void print()
    {
        cout << "id = " << m_id << ", name = " << m_name << endl;
    }
private:
    int m_id;
    string m_name;
};

void uniquePtrAddDeleter()
{
	// 1. 匿名的删除器没有捕获外部变量
	// 2. 匿名的删除器捕获了外部变量
	shared_ptr<int> ptr1(new int(3), [](int* p) {delete p; });
	using funcPtr = void(*)(Test*);
	unique_ptr<Test, funcPtr> ptr2(new Test[3], [](Test* p) {delete []p; });

	unique_ptr<Test, function<void(Test*)>> ptr3(new Test[3], [=](Test* p) {delete []p; });
}


int main()
{
	return 0;
}
#endif