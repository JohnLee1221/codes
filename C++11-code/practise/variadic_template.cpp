#include <iostream>
using namespace std;

void print(){}

template <typename T,typename ...Type>
void print(const T& firstArg,const Type&... args)
{
    std::cout<<firstArg + 100<<"\t"<<sizeof...(args)<<endl;
    print(args...);
}

int main()
{
    print(1,2,3,4,5);

    return 0;
}