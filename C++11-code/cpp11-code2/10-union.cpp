#include <iostream>
using namespace std;

#if 0
class Base
{
public:
    Base() {};
};
union Test
{
    // �������pod������Ϊ���ݳ�Ա
    //string str; // c++98���﷨����
    //Base b;
    // ��������־�̬��Ա(��Ա����, ��Ա����)
    static int num;
    static int print() {
        // num = 900;
        return 100;
    }
    // �������������
    int num1;
    // int& ref = num1; error
};
int Test::num = 10;

class Teacher
{
public:
    Teacher() {}
    void setText(string s)
    {
        name = s;
    }
private:
    string name;
};
union Student
{
    Student() 
    { 
        new (&name)string;
    } 
    ~Student() {}
    int id;
    Teacher t;
    string name;
};


struct Foreigner
{
    Foreigner(string a, string p) :addr(a), phone(p) {}
    string addr;
    string phone;
};

class Person
{
public:
    enum class Category :char {Student, Local, Foreign};
    Person(int num) :number(num), c(Category::Student) {}
    Person(string str) :idNum(str), c(Category::Local) {}
    Person(string a, string p) :fore(a, p), c(Category::Foreign) {}
    ~Person() {}

    void print()
    {
        switch (c)
        {
        case Category::Student:
            cout << "Student school number: " << number << endl;
        	break;
        case Category::Local:
            cout << "Local people ID number: " << idNum << endl;
            break;
        case Category::Foreign:
            cout << "Foreigner address: " << fore.addr
                << ", phone: " << fore.phone << endl;
            break;
        }
    }
private:
    Category c;
    union
    {
        int number;
        string idNum;
        Foreigner fore;
    };
};
int main()
{
    Person p1(9727);
    Person p2("1111222333XY");
    Person p3("ɰ������", "1301133456");
    p1.print();
    p2.print();
    p3.print();
    cout << endl << endl << endl;

    Student s;
    s.name = "����·��";
    s.t.setText("���Ǻ�����");
    cout << "s.name = " << s.name << endl;
#if 0
    Test t1;
    t1.num1 = 100;
    cout << "sattic num value: " << t1.num << endl;
    cout << "num1 value: " << t1.num1 << endl;
    t1.print();
    Test::print();

    Test t2;
    t2.num = 50;
    cout << "sattic num value: " << t2.num << endl;
    cout << "sattic num value: " << t1.num << endl;
#endif

    return 0;
}

#endif