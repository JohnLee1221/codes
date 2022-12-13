#ifndef _CALLBACK_H_
#define _CALLBACK_H_

#include <iostream>
#include <vector>

using funcPtr = void(*)(std::string);

class Precess
{
public:
    Precess() = default;
    void PreFunc(funcPtr f,std::string str);
};

#endif  //_CALLBACK_H_