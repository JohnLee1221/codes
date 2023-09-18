#include <iostream>
using namespace std;

int main()
{
    char arr[5] = {'a','2','3','4','5'};

    for (int i = 0;i < 5;i++)
    {
        cout<<(int)arr[i]<<endl;
    }

    int arr2[2] = {33,98};
    cout<<(char)arr2[0]<<"\t"<<(char)arr2[1]<<endl;

    return 0;
}