#include <iostream>
using namespace std;

class Base
{
public:
    Base(string name,int age) : m_name(name),m_age(age)
    {
        cout<<"name: "<<m_name<<"\t"<<"age: "<<m_age<<endl;
    }
    
    void func(int num)
    {
        cout<<"the function of base"<<endl;
    }
        
public:
    string m_name;
    int m_age;
};

class Derived : public Base
{
public:
    Derived(string name,int age) : Base(name,age){}				//传统继承基类的构造函数写法
    //using Base::Base;											//使用using来声明使用基类的构造函
	
 	void func()
    {
        cout<<"the function of derived"<<endl;
    }
    using Base::func;											//使用using来声明使用基类的同名函数
};

int main()
{
  Base b("Tom",18);												//base类构造
  Derived d("Jerry",12);										//通过继承base类的构造来构造derive类
  
  b.func(1);														//通过base类的对象调用base类func方法
  d.func();														//通过derived类的对象调用derived类的方法
  
  d.Base::func(1);												//通过derived类的对象调用base类的方法
  d.func(1);													//使用using关键字后，通过derived类的对象调用base类的方法
    
  return 0;
}