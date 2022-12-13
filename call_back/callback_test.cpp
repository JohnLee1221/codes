#include <iostream>
#include <vector>
#include <functional>
#include "callback.h"

int main()
{
    Precess p;


    auto callback = [](std::string str){
        std::cout<<str<<std::endl;
    };

    std::string test_str = "lalala hahaha";
    p.PreFunc(callback,test_str);

    return 0;
}