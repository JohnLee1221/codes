#include <iostream>
using namespace std;

//struct DataType
//{
//    //DataType(int a,string b): num(a),str(b){}
//
//    int num;
//    string str;
//};

class Person
{
public:
    Person(string name,int age): m_name(name),m_age(age){}

public:
    string m_name;
    int m_age;
    //DataType data;
};

//Person func()
//
//    return Person("Tom",18);
//}

int main()
{
    Person p1{"Jerry",20};

    //forward模板参数类型为左值引用的时候，生成的是左值
    //Person && p2 = std::forward<Person &> (p1);

    //forward模板参数类型为非左值引用时，生成的是右值
    Person && p3 = std::forward<Person> (p1);
    Person && p4 = std::forward<Person &&> (p1);
    Person & p5 = std::forward<Person &> (p1);

    return 0;
}

