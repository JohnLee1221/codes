#include <iostream>

void Sort(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i -1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                int tmp = *(ptr + j + 1);
                *(ptr + j + 1) = *(ptr + j);
                *(ptr + j) = tmp;
            }
        }
    }
}

void Compare1(int *ptr) {
    int test = 100;
    *ptr = *ptr < test ? test : *ptr;
}

void Assign(int *ptr) {
    int *tmp = new int(100);
    ptr = tmp;
}

int main() {
    // int arr[] = {1, 16, 4, 6, 9, 18, 3, 8, 20};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // Sort(arr, size);
    // for (int i = 0; i < size; i++) {
    //     std::cout << arr[i] << "  ";
    // }
    // std::cout << std::endl;

    // int *ptr = new int[10];
    // for (int i = 0; i < 10; i++) {
    //     ptr[i] = (10 - i) * 10;
    // }
    // Sort(ptr, 10);

    // for (int i = 0; i < 10; i++) {
    //     std::cout << ptr[i] << "  ";
    // }
    // std::cout << std::endl;

    // delete[] ptr;


    int *value = new int(10);
    Assign(value);
    std::cout << *value << std::endl;

    return 0;
}