#include <iostream>
#include <map>
using namespace std;

//use typedef to declare a template
template <typename T>
struct MyMap
{
    typedef map<int,T> map_temp;
};

void typedef_template()
{   

    MyMap<string>::map_temp map1;

    map1.insert(make_pair(1,"Tomo"));
    map1.insert(make_pair(2,"Jerry"));

    for(auto it = map1.begin();it != map1.end();it ++)
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }
}


//use using to declare a template
template <typename T>
using myMap = map<int,T>;

void using_template()
{
    myMap<string> map2;
    map2.insert(make_pair(20,"xiaoming"));
    map2.insert(make_pair(24,"xiaoliang"));

    for(auto it = map2.begin();it != map2.end();it ++)
    {
        cout<<it->second<<"\t"<<it->first<<endl;
    }
}

//
void typedef_test()
{
    typedef unsigned int uint_t;
    typedef int (*Ptr)(int);

    uint_t a = 10;
    Ptr p = [](int b){return b;};

    cout<<"typedef_test: "<<a<<endl;
    cout<<"typedef_test: "<<p(1000)<<endl;
}

void using_test()
{
    using uint_t = unsigned int;
    using Ptr = char*(*)(char*);

    uint_t aa = 100;
    Ptr ptr = [](char* a){return a;};

    cout<<"using_test: "<<aa<<endl;
    cout<<"using_test: "<<ptr("hahaha")<<endl;
}

int main()
{
    typedef_test();
    using_test();

    typedef_template();
    using_template();

    return 0;
}