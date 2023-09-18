#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class Base
{
public:
    Base(T t): num(t){}

    T output()
    {
        return num;
    }

private:
    T num;
};

template<typename T>
void getData(std::vector<T> v)
{
    for(auto itor : v)
    {
        std::cout<<itor.output()<<std::endl;
    }
}

void test01()
{
    Base<std::string> b1("Hello");
    std::cout<< b1.output() <<std::endl;

    std::vector<Base<std::string>> v1;
    v1.push_back(Base<std::string>("lalala"));
    v1.push_back(Base<std::string>("hahaha"));

    getData<Base<std::string>>(v1);

    
    using Vector = std::vector<Base<std::string>>;
    Vector v2;
    v2.push_back(Base<std::string>("wawawa"));
    getData<Base<std::string>>(v2);

    std::shared_ptr<std::vector<Base<std::string>>> ptr = std::make_shared<std::vector<Base<std::string>>>(v2);

    std::cout<< v2.front().output() <<std::endl;
    auto test02 = ptr->front();
    std::cout<< ptr->data()->output() <<std::endl;
    
    std::unique_ptr<std::vector<Base<std::string>>> ptr2 = std::move(ptr);
    auto test= ptr2.front();

}

int main()
{
    test01();

    return 0;
}