#include <iostream>
using namespace std;

typedef int abbb;
#if 0
#if 0
void aaa();


// 1. const 和 constexpr
const int getNum()
{
    return 12;
}

void test(int cond)
{
    // 数组
    int array[getNum()] = { 0 };
    // 枚举
    enum Mode { M1 = getNum(), M2 };
    // 条件判断
    switch (cond)
    {
    case getNum():
        break;
    default:
        break;
    }
}
#endif
// 2. constexpr 与自定义类型
class Person
{
public:
    void print()
    {
        cout << "id = " << id << endl;
    }
    int id;
};


// 3. constexpr 与模板
struct Student 
{
    // 常量构造函数
    const char* name;
    int age;
};

// 定义函数模板
template<typename T>
constexpr T dispaly(T t) 
{
    return t;
}

void templateFunc()
{
    // 1. 推导出的是非常量表达式

    // 2. 推导出的是常量表达式
}

// .cpp --> exe
// 1. 预处理 2.编译 3.汇编 4. 链接 -> 得到exe
int main()
{
    const Student s(1, 2);
    return 0;
}


class Test
{
public:
    int getI()
    {
        return this->i;
    }
    void setI(int i)
    {
        this->i = i;
    }
    void aa() {}
private:
    int a;
protected:
    int i;
    int b;
};

class SubTest : public Test
{
public:
    void func() {}
protected:
    int h;
};

class SubSubTest : public SubTest
{
};


void functest()
{
    Test t;
    int a = t.getI();

    Test* tt = new Test;
    tt->setI(3);
}
#endif