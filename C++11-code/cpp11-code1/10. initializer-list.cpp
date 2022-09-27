#include <iostream>
using namespace std;

#if 0
// 1. 使用初始化列表初始化变量
struct Person
{
    int id;
    string desc;
};

void initListTest()
{
    Person p1 = { 520, "i love you" };
    Person p2{ 250, "you love me" };
    int a = 666;
    int a2(9);
    int a3 = { 1314 };
    int a4{ 1314 };
    int arr1[] = { 1, 2, 3 };
    int arr2[]{ 1, 2, 3 };
    int* array = new int[3]{ 1,2,3 };
    // int arr3[3]{ 1, 2, 3 };
}

// 2. 聚合体
struct T1
{
    int x;
    long y;
    float f;
    int z[3]{ 1,2,3 };
    int n = 9;
protected:
    // int kk;
    static int ss; // 不能在初始列表{}中初始化
};
int T1::ss = 4;

void initT1()
{
    T1 t{ 1,1,1.1f };
    T1 t1{ 1,1,1.1f,{22,33,44},99};
}


// 3. 非聚合体
struct T2
{
    T2(int a, string b) :m_x(a), m_s(b) {}
    T2(int a, double b, int c) : m_x(a), m_z(b), m_y(c) {}
    T2(int a, int b)
    {
        m_x = a;
        m_y = b;
    }
    virtual void print()
    {
        cout << "x: " << m_x << ", y: " << m_y << ", z: " << m_z << endl;
    }

private:
    int m_x = 0;
    int m_y = 0;
    double m_z = 0;
    string m_s;
};

#if 1
Person funcPerson()
{
    // 用在函数返回值上
    // return Person();
    Person p{ 1, "hello" };
    return { 1, "hello" };
}
#endif

// 4. 
void traversal(std::initializer_list<int> a)
{
    cout << "size: " << a.size() << endl;
    // 遍历
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main(void)
{
    traversal({1,3,4,5,6,6});
    return 0;
}
#endif