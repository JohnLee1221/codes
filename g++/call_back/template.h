#include <iostream>
using namespace std;

typedef void (*fp)(string,int);

void declaration(fp ptr,string name,int num)
{
    cout<<"*****************"<<endl;
    ptr(name,num);
    cout<<"~~~~~~~~~~~~~~~~~"<<endl;
}