#include <iostream>

using funcPtr = void(*)(std::string);

void callback (std::string str)
{
    std::cout<<str<<std::endl;
}

void test(funcPtr f)
{
    std::string a = "lalala";
    f(a);
}

int main()
{
    test(callback);

    return 0;
}