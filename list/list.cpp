#include <iostream>

struct Node {
  int data;
  Node* next;
};

class List {
 public:
  List() : head(nullptr) {}

  void Push(int num) {
    Node* element = CreateNode(num);
    Node* temp = head;
    if (temp == nullptr) {
      head = element;
    } else {
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = element;
    }
  }

  void Insert(int index, int num) {
    Node* element = CreateNode(num);
    Node* temp = head;
    if (index == 0) {
      element->next = head;
      head = element;
    } else {
      for (int i = 0; i < index-1; i++) {
        temp = temp->next;
      }
      element->next = temp->next;
      temp->next = element;
    }
  }

  void Delete(int index) {
  }

  void Print() {
    Node* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << "\t";
      temp = temp->next;
    }
    std::cout << "\n";
  }

 private:
  Node* CreateNode(int num) {
    Node* temp = new Node();
    temp->data = num;
    temp->next = nullptr;
    return temp;
  }

 private:
  Node* head;
};

int main() {
  List list;
  list.Push(10);
  list.Push(20);
  list.Push(30);
  list.Push(40);
  list.Insert(0,100);

  list.Print();
  return 0;
}



