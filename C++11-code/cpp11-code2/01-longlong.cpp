#include <iostream>
using namespace std;

#if 0
int main()
{
    // �з��� 
    long int n = 100L;
    // signed long long
    // long long int
    // signed long long int
    long long num1 = 11111LL;
    // unsigned long long int
    unsigned long long num2 = 1111ULL;

    // ռ�ڴ��С������ 8 �ֽ�

    cout << "long long max: " << LLONG_MAX
        << ", long long min: " << LLONG_MIN
        << ", unsigned long long max: " << ULLONG_MAX << endl;

    // �͵ȼ� int �� �ߵȼ� int
    char c = 6;
    long long d = c;
    // ��׼ int �Զ��� int
    typedef int aa;
    aa bb = 5;
    int num = bb;
    long long num1 = bb;
    // �з���int �޷��� int (�ڴ��С��ͬ) == > �з��� ==> �޷�������
    unsigned int num2 = num1;
    return 0;
}
#endif