#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr = {9, 6, 3, 8, 5, 2, 7, 4, 1, 0};
    sort(arr.begin(),arr.end());

    for(auto it : arr)
    {
        cout<<it<<endl;
    }

    return 0;
}

