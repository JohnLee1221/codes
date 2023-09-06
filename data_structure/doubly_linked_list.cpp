#include <iostream>

struct Node {
  int data{};
  Node *prev{};
  Node *next{};
};

class DoublyLinkedList {
 public:
  // creats a new Node and returns pointer to it.
  Node* GetNewNode(const int& value) {
    Node *tmp_node = new Node({value, nullptr, nullptr});
    return tmp_node;
  }

  // inserts a Node at head of doubly linked list.
  void InserAtHeader(const int& value) {
    Node *insert_node = GetNewNode(value);
    if (header_ == nullptr) {
      header_ = insert_node;
    } else {
      insert_node->next = header_;
      header_->prev = insert_node;
      header_ = insert_node;
    }
  }

  // inserts a Node at tail of doubly linked list.
  void InsertAtTail(const int& value) {
    Node *insert_node = GetNewNode(value);
    if (header_ == nullptr) {
      header_ = insert_node;
    } else {
      Node *traverse_ptr = header_;
      while (traverse_ptr->next != nullptr) {
        traverse_ptr = traverse_ptr->next;
      }
      traverse_ptr->next = insert_node;
      insert_node->prev = traverse_ptr;
    }
  }

  // prints all the elements in linked list in forward traversal order
  // Print()
  void Print() {
    Node *traverse_ptr = header_;
    std::cout << "nullptr <- "; 
    while (traverse_ptr != nullptr) {
      std::cout << traverse_ptr->data << " <-> ";
      traverse_ptr = traverse_ptr->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  // prints all the elements in linked list in reverse traversal order
  void ReversePrint() {
    Node *traverse_ptr = header_;
    while (traverse_ptr->next != nullptr) {
      traverse_ptr = traverse_ptr->next;
    }
    while (traverse_ptr != nullptr) {
      std::cout << traverse_ptr->data << " <-> ";
      traverse_ptr = traverse_ptr->prev;
    }
    std::cout << "nullptr" << std::endl;
  }

  void Reverse() {
    if (header_ == nullptr) {
      return;
    } else {
      Node *traverse_ptr = header_;
      while (traverse_ptr->next != nullptr) {
        traverse_ptr = traverse_ptr->next;
      }
      Recursion(header_);
      header_ = traverse_ptr;
    }
  }

 private:
  void Recursion(Node *iter) {
    if (iter->next != nullptr) {
      Recursion(iter->next);
    } 
    Node *tmp_ptr = iter->prev;
    iter->prev = iter->next;
    iter->next = tmp_ptr;
  }

 private:
  Node *header_{};
};

int main() {
  DoublyLinkedList d_list;
  d_list.InserAtHeader(10);
  d_list.InserAtHeader(20);
  d_list.InserAtHeader(30);
  d_list.InsertAtTail(50);

  d_list.Print();
  // d_list.ReversePrint();
  d_list.Reverse();
  d_list.Print();

  return 0;
}