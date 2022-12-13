#include <iostream>

#include <iostream>
using namespace std;

int *get10(){
    int a = 10;
    int *b = &a;
    return b;
}

int *get20(){
    int c = 200;
    int *b = &c;
    return b;
}

// int *get30(){
//     int a = 1000;
//     int *b = &a;
//     return b;
// }

int main() {
    int *c10 = get10();
    // int *c20 = get20();
    // int *c30 = get30();
    int b = 100;
    int* p = &b;
    cout << *c10 << endl;
    cout << *p << endl;
    // cout << *c30 << endl;
    return 0;
}