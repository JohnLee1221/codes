#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#if 0
// 1. 基于范围的for循环
void traverseVector()
{
    vector<int> t{ 1,2,3,4,5,6 };
    // 基于边界的for循环
    for (auto it = t.begin(); it != t.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 基于范围的for循环 (循环过程中修改容器中元素的值)
    for (auto& it : t)
    {
        it++;
    }
    cout << endl;
    // 基于范围的for循环
    for (const auto& it : t)
    {
        cout << it << " ";
    }
    cout << endl;

}

// 2. 遍历关系容器 - map
void traverseMap()
{
    map<int, string> m{ {1, "lucy"},{2, "lily"},{3, "tom"} };
    // 2.1 基于边界的for循环遍历
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << "key: " << it->first 
            << ", value: " << it->second << endl;
    }

    // 2.2 基于范围的for循环遍历
    for (auto it : m)
    {
        cout << "key: " << it.first
            << ", value: " << it.second << endl;
    }
}

// 3. 元素只读
void traverseReadOnly()
{
    // 数据不允许重复, 数据默认升序排列
    // 集合中的数据只读
    set<int> st{ 11,52,13,24,5,6 };
    map<int, string> m{ {1, "lucy"},{2, "lily"},{3, "tom"} };
    
    for (auto& it : st)
    {
        cout << it << " ";
    }

    for (auto& it : m)
    {
        cout << "key: " << it.first
            << " ,value: " << it.second << endl;
    }
}

// 4. 访问次数
vector<int> v{ 1,2,3,4,5,6 };
vector<int>& getRange()
{
    cout << "get vector range..." << endl;
    return v;
}

void test()
{
    for (auto& item : getRange())
    {
        cout << item << " ";
    }
    cout << endl;
}


int main()
{
    test();

    return 0;
}
#endif