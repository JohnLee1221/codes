#include <iostream>

void func() {
  int arr[]={15,11,6,13,1,4,13,12,17,17,11,3,1,17,17};
  int arr_size=sizeof(arr)/sizeof(arr[0]);
  int hash_arr[18];
  for (int k=0; k<18; k++) {
    hash_arr[k]=0;
  }
  for (int i=0; i<arr_size; i++) {
    int num = arr[i];
    hash_arr[num]++;
  }
  for (int j=0; j<18; j++) {
    std::cout << hash_arr[j] << std::endl;
  }
}

int main() {
  func();
  return 0;
}