#include <iostream>
using namespace std;

#if 0
// 1. 委托构造函数
//#if 0
//class Test
//{
//public:
//    Test(int max)
//    {
//        this->m_max = max > 0 ? max : 100;
//    }
//
//    Test(int max, int min)
//    {
//        this->m_max = max > 0 ? max : 100;              // 冗余代码
//        this->m_min = min > 0 && min < max ? min : 1;
//    }
//
//    Test(int max, int min, int mid)
//    {
//        this->m_max = max > 0 ? max : 100;             // 冗余代码
//        this->m_min = min > 0 && min < max ? min : 1;  // 冗余代码
//        this->m_middle = mid < max&& mid > min ? mid : 50;
//    }
//
//    int m_min;
//    int m_max;
//    int m_middle;
//};
//#else
//class Test
//{
//public:
//    Test(int max)
//    {
//        this->m_max = max > 0 ? max : 100;
//    }
//
//    Test(int max, int min):Test(max)
//    {
//        this->m_min = min > 0 && min < max ? min : 1;
//    }
//
//    Test(int max, int min, int mid):Test(max, min)
//    {
//        this->m_middle = mid < max&& mid > min ? mid : 50;
//    }
//
//    int m_min;
//    int m_max;
//    int m_middle;
//};
//
//#endif
//
//// 2. 继承构造函数
////    -- 子类中使用using继承父类构造函数 (C++11)
////    -- 子类中使用using使用父类中被隐藏的类函数 (C++98/03)
//#if 0
//class Base
//{
//public:
//    Base(int i) :m_i(i) {}
//    Base(int i, double j) :m_i(i), m_j(j) {}
//    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}
//
//    void func(int i)
//    {
//        cout << "base class: i = " << i << endl;
//    }
//
//    void func(int i, string str)
//    {
//        cout << "base class: i = " << i << ", str = " << str << endl;
//    }
//
//
//protected:
//    int m_i;
//    double m_j;
//    string m_k;
//};
//
//class Child : public Base
//{
//public:
//    Child(int i) :Base(i) {}
//    Child(int i, double j) :Base(i, j) {}
//    Child(int i, double j, string k) :Base(i, j, k) {}
//
//    void func()
//    {
//        cout << "child class: i'am luffy!!!" << endl;
//    }
//};
//#else
//class Base
//{
//public:
//    Base(int i) :m_i(i) {}
//    Base(int i, double j) :m_i(i), m_j(j) {}
//    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}
//
//    void func(int i)
//    {
//        cout << "base class: i = " << i << endl;
//    }
//
//    void func(int i, string str)
//    {
//        cout << "base class: i = " << i << ", str = " << str << endl;
//    }
//
//
//protected:
//    int m_i;
//    double m_j;
//    string m_k;
//};
//
//class Child : public Base
//{
//public:
//    using Base::Base;
//    using Base::func;
//    void func()
//    {
//        cout << "child class: i'am luffy!!!" << endl;
//    }
//};
//#endif
//int main()
//{
//    Test t(90, 30, 60);
//    cout << "min: " << t.m_min 
//        << ", middle: " << t.m_middle 
//        << ", max: " << t.m_max << endl;
//
//    Child c1(1);
//    Child c2(1, 1.2);
//    Child c3(1, 1.2, "hello");
//
//    c3.func(1, "hello");
//
//    return 0;
//}
#endif