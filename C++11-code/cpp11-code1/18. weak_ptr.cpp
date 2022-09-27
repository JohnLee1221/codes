#include <iostream>
#include <memory>
using namespace std;

#if 0
// 1. weak_optr 初始化
void weakPtrInit()
{
	shared_ptr<int> ptr1(new int(3));
	weak_ptr<int> wp(ptr1);
	weak_ptr<int> wp1(wp);
	weak_ptr<int> wp2 = wp;
	weak_ptr<int> wp3;
	cout << "user_count: " << wp.use_count() << endl;
    cout << "expired: " << wp.expired() << endl;

	shared_ptr<int> ptr2 = wp.lock();
	cout << "value: " << *ptr2 << endl;

	ptr1.reset();
    cout << "user_count: " << wp.use_count() << endl;
    cout << "expired: " << wp.expired() << endl;

	wp.reset();
}

// 2. weak_ptr的应用 - 1
#if 1
struct Test
{
    shared_ptr<Test> getSharedPtr()
    {
        return shared_ptr<Test>(this);
    }

    ~Test()
    {
        cout << "class Test is destruct ..." << endl;
    }

};
#else
#endif

void weakPtrTest1()
{
    shared_ptr<Test> sp1(new Test);
    cout << "use_count: " << sp1.use_count() << endl;
    shared_ptr<Test> sp2 = sp1->getSharedPtr();
    cout << "use_count: " << sp1.use_count() << endl;
}

// 3. weak_ptr的应用 - 2

struct TA;
struct TB;

struct TA
{
    shared_ptr<TB> bptr;
    ~TA()
    {
        cout << "class TA is destruct ..." << endl;
    }
};

struct TB
{
    shared_ptr<TA> aptr;
    ~TB()
    {
        cout << "class TB is destruct ..." << endl;
    }
};

void weakPtrTest2()
{
    shared_ptr<TA> ap(new TA);
    shared_ptr<TB> bp(new TB);
    cout << "TA object use_count: " << ap.use_count() << endl;
    cout << "TB object use_count: " << bp.use_count() << endl;

    ap->bptr = bp;
    bp->aptr = ap;
    cout << "TA object use_count: " << ap.use_count() << endl;
    cout << "TB object use_count: " << bp.use_count() << endl;
}

int main()
{
    weakPtrTest2();
	return 0;
}
#endif