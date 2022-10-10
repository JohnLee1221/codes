#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //int a = 100;
    //char b = 'a';
    //int *ptr = nullptr;
    //auto test = ptr;

    //const int aa = 10;
    //auto temp1 = aa;            //值传递，自动类型推导，不会推导成const
    //auto temp2 = &aa;           //地址传递或者引用，自动类型推导，会推导成const

    //temp1 = 20;
    //temp2 = &a;

    //cout<<*temp2<<endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;
    for(it = v.begin();it != v.end();it++)
    {
        cout<<*it<<endl;
    }

    return 0;
}