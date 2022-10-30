#include <iostream>
#include <memory>

class Person
{
public:
    Person(int a)
    {
        std::cout<<a<<std::endl;
        std::cout<<"construt function"<<std::endl;
    }

    ~Person()
    {
        std::cout<<"distruct function"<<std::endl;
    }
    
};

void test()
{
    std::unique_ptr<int> ptr1(new int(100));
    //std::unique_ptr<int> ptr2 = ptr1;
    std::unique_ptr<int> ptr3 = std::move(ptr1);
    //std::unique_ptr<int> ptr4 = std::make_shared<int> (1000);
    std::unique_ptr<int> ptr5;
    ptr5.reset(new int(111));
}

void func()
{
    //删除器
    using deleteFunc = void(*)(Person *);

    std::unique_ptr<Person,deleteFunc> ptr1(new Person[3]{1,2,3},[](Person *p){
        delete p; 
        std::cout<<"distruct function"<<std::endl;
    });

    //std::unique_ptr<Person[]> ptr2(new Person[5]{1,2,3,4,5});
    //std::cout<<"***************************"<<std::endl;
    //std::shared_ptr<Person[]> ptr3(new Person[5]{1,2,3,4,5});

}

int main()
{
    //test()
    func();
    
    return 0;
}