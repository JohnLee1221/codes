#include <iostream>
#include <memory>
using namespace std;

#if 0
// 1. shared_ptr 的初始化
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
void sharedPtrInit()
{
	// 通过构造函数
	shared_ptr<int> ptr3;
	shared_ptr<int> ptr1(new int(5));
	shared_ptr<int> ptr2(new int[5]{1,2,3,4,5});
	shared_ptr<int> ptr4(nullptr);
	cout << "ptr3 user_count: " << ptr3.use_count() << endl;

	// 通过拷贝构造函数
	shared_ptr<int> ptr5 = ptr1;
	cout << "ptr5 user_count: " << ptr5.use_count() << endl;

	// 通过移动构造函数
	shared_ptr<int> ptr6 = move(ptr5);
	cout << "ptr5 user_count: " << ptr5.use_count() << endl;
    cout << "ptr6 user_count: " << ptr6.use_count() << endl;
	
	// 使用 make_shared
	shared_ptr<int> ptr7 = make_shared<int>(8);
	
	shared_ptr<Test> ptr9 = make_shared<Test>();
	shared_ptr<Test> ptr8 = make_shared<Test>(20, "tom");
    
	// 使用reset初始化
	//ptr7.reset();
    //cout << "ptr7 user_count: " << ptr7.use_count() << endl;

	ptr7.reset(new int(8));
    cout << "ptr7 user_count: " << ptr7.use_count() << endl;

	shared_ptr<Test> ptr9(new Test[5]);

	// 初始化注意事项
	int* num = new int(4);
	// 最后得到的num的引用计数不等于2
	shared_ptr<int> ppp(num);
	shared_ptr<int> ppp1(num);
}

// 2. shared_ptr对内存的操作
void sharedPtrOP()
{
    shared_ptr<Test> ptr(new Test);
	// 1. 通过智能指针直接操作内存
	ptr->print();

	// 2. 取出指针地址再操作
	Test* p = ptr.get();
	p->print();
}

// 3. shared_ptr 指定删除器
void deleteIntPtr(int* ptr)
{
	delete ptr;
	cout << "deleteIntPtr called..." << endl;
}
void sharedPtrAddDeleter()
{
	// 使用自定义的删除器
	shared_ptr<int> ptr(new int(8), deleteIntPtr);
	shared_ptr<int> ptr1(new int[3], [](int* arr) {
		delete[]arr;
		cout << "int array delete..." << endl;
	});

	// 使用C++11提供的默认删除器
    shared_ptr<int> ptr2(new int(8), default_delete<int>());
    shared_ptr<int> ptr3(new int[3], default_delete<int[]>());
    shared_ptr<Test> ptr4(new Test[3], default_delete<Test[]>());
}

// 4. 自己编写一个初始化shared_ptr的函数, 并且支持删除数组类型的地址


int main()
{
	return 0;
}
#endif