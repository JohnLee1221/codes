#include <iostream>

#define STRING "Hello Word."

constexpr char Str1[] = "HaHaHa";
const std::string Str2 = "LaLaLa";

class Base
{
public:
    Base() = default;
    void func()
    {
        std::cout<<num_<<std::endl;
    }
private:
    enum {num_ = 1000};
    // int num_;
};

int main()
{
    std::cout<<STRING<<std::endl;
    std::cout<<Str1<<std::endl;
    std::cout<<Str2<<std::endl;

    Base b;
    b.func();

    return 0;
}