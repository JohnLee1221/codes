#include <iostream>
using namespace std;

class Test1
{
public:
    Test1(int max,int min,int middle): m_max(max),m_min(min),m_middle(middle)
    {
        cout<<m_max<<"\t"<<m_middle<<"\t"<<m_min<<endl;
    }

    Test1(int num):Test1(num,0,5){};

    Test1():Test1(100,0,5){};

public:

    int m_max;
    int m_min;
    int m_middle;
};

int main()
{
    Test1 t1 {10,-1,50};
    Test1 t2 {1000};
    Test1 t3;

    return 0;
    
    
}