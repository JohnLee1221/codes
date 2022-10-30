#include <iostream>
#include <memory>

void func()
{
    std::shared_ptr<int> ptr1{new int{100}};
    std::shared_ptr<int> ptr2 = ptr1;

    std::weak_ptr<int> wp1;
    std::weak_ptr<int> wp2 = ptr1;
    std::weak_ptr<int> wp3{ptr1};
    std::weak_ptr<int> wp4{wp3};

    std::cout<<ptr1.use_count()<<std::endl;
    std::cout<<wp1.use_count()<<std::endl;
    std::cout<<wp3.use_count()<<std::endl;
    std::cout<<wp4.use_count()<<std::endl;
    
    std::cout<<(wp3.expired() == 1 ? "ture" : "false")<<std::endl;
    wp3.reset();
    std::cout<<(wp3.expired() == 1 ? "ture" : "false")<<std::endl;

    ptr2.reset();
    std::cout<<ptr1.use_count()<<std::endl;
    ptr2 = wp2.lock();
    std::cout<<ptr1.use_count()<<std::endl;

}



int main()
{
    shard_ptr_caution();

    return 0;
}