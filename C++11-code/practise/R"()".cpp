#include <iostream>
using namespace std;

//原始字面量

int main()
{
    cout<<"Hello \test"<<endl;
    cout<<R"(Hello \test)"<<endl;

    string st1;
    string st2;

    // st1 = "报数
    // 1
    // 2
    // 3
    // 4
    // 5";
    // cout<<st1<<endl;

    st2 = R"(报数\
    1
    2
    3
    4
    5)";
    cout<<st2<<endl;

    return 0;
}