#include <iostream>
#include "template.h"
using namespace std;

void information(string name,int age)
{
    cout<<name<<"\t"<<age<<endl;
}

int main()
{
    string name = "Tom";
    int age = 20;

    declaration(information,name,age);

    return 0;
}