#include <iostream>

struct Node {
  int data;
  Node* next;
};

Node* head = nullptr;

void foo() {
  Node* temp = new Node{100,nullptr};
  head = temp;
  temp = new Node{200,nullptr};
  head->next = temp;
  temp = new Node{300,nullptr};
  head->next->next = temp;

  for (Node* ptr = head; ptr != nullptr; ptr++) {
    std::cout << ptr->data << std::endl;
  }
}

int main() {
  foo();
  return 0;
}