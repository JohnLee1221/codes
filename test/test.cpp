#include <iostream>
#include "enum.h"

int main()
{
    int temp = Test::num_;
    Test t;
    t.func();

    std::cout<<TEST_NUM<<std::endl;

    return 0;
}