#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Person
{
public:
    Person(){cout<<"construct function"<<endl;}
    ~Person(){
        cout<<"distruct function"<<endl;}
};

int main()
{
    //vector<int> v;
    //std::shared_ptr<vector<int>> ptr1 = std::make_shared<vector<int>>(v);
    std::shared_ptr<vector<int>> ptr1 = std::make_shared<vector<int>>(vector<int>());
    ptr1->push_back(100);
    ptr1->push_back(200);
    for(auto it = ptr1->begin();it != ptr1->end();it ++)
    {
        cout<<*it<<endl;
    }

    for(auto it : *ptr1)
    {
        cout<<it<<endl;
    }

    std::shared_ptr<Person> ptr2{new Person[3],std::default_delete<Person[]>()};

    return 0;
}