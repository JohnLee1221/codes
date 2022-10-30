#include <iostream>
#include <memory>
using namespace std;

template <class T>
class Person
{
public:
    string m_name;
    int m_age;
    T sub_element;
};

void test()
{
    std::shared_ptr<int> num1{new int(100)};

    int a = 100;
    int *p = &a;
    //std::shared_ptr<int> num2{p};

    Person<int> p1{"Tom",18,3000};
    Person<std::string> p2{"Jerry",20,"salary:4000"};

    std::shared_ptr<Person<int>> p3{new Person<int>{p1}};
    //std::shared_ptr<Person<std::string>> p4{"John",30,"3000"};

    cout<<p1.m_name<<"\t"<<p1.m_age<<"\t"<<p1.sub_element<<endl;
    cout<<p2.m_name<<"\t"<<p2.m_age<<"\t"<<p2.sub_element<<endl;
    cout<<p3->m_name<<"\t"<<p3->m_age<<"\t"<<p3->sub_element<<endl;

    cout<<p3.use_count()<<endl;   
}

void construct_func()
{
    std::shared_ptr<int> ptr1{new int{100}};        //初始化列表，初始化共享指针
    std::shared_ptr<int> ptr2 = ptr1;               //拷贝构造,初始化共享指针
    std::shared_ptr<int> ptr3{std::move(ptr1)};    //移动构造，初始化共享指针
    std::shared_ptr<int> ptr4 = std::move(ptr1);    //移动构造，初始化共享指针
    std::shared_ptr<int> ptr6 = ptr3;    //移动构造，初始化共享指针

    std::shared_ptr<int> && ptr5 = std::shared_ptr<int>{new int{10}};   //

    cout<<ptr1.use_count()<<endl;
    cout<<ptr2.use_count()<<endl;
    cout<<ptr3.use_count()<<endl;
    cout<<ptr4.use_count()<<endl;
    cout<<ptr5.use_count()<<endl;

}

void make_shared_func()
{
    std::shared_ptr<int> ptr1 = make_shared<int> (100);
    std::shared_ptr<int> ptr2 = make_shared<int> ();
    Person<int> p{"lalala",1,1111};
    std::shared_ptr<Person<int>> ptr3 = make_shared<Person<int>> (p);

    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;
    cout<<ptr3->m_name<<"\t"<<ptr3->m_age<<"\t"<<ptr3->sub_element<<endl;
    //cout<<*ptr3.get()<<endl;

}

void reset_func()
{
    std::shared_ptr<int> ptr1;
    ptr1.reset(new int{100});
    std::shared_ptr<int> ptr2 = ptr1;
    cout<<ptr1.use_count()<<endl;
    cout<<ptr2.use_count()<<endl;

    ptr2.reset();
    cout<<ptr1.use_count()<<endl;
    cout<<ptr2.use_count()<<endl;
}

void get_func()
{
    std::shared_ptr<int> ptr1;
    ptr1.reset(new int{100});
    std::shared_ptr<int> ptr2 = ptr1;
    cout<<ptr1.use_count()<<endl; 
    cout<<ptr2.use_count()<<endl; 
 
    cout<<ptr1<<endl;
    cout<<ptr2<<endl;
    cout<<ptr1.get()<<endl;
    cout<<ptr2.get()<<endl;
}


int main()
{
    //test();
    //construct_func();
    //make_shared_func();
    //reset_func();
    get_func();

    return 0;
}