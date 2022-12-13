#include <iostream>
#include <vector>

#include "callback.h"

void Precess::PreFunc(funcPtr f,std::string str)
{
    std::cout<<"step1: ****"<<std::endl;
    f(str);
}
