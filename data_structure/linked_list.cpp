#include <iostream>
#include <memory>

struct Node {
  int data{};
  Node *next{};
};

class LinkedList {
 public:
  LinkedList() = default;

  void Print() {
    Node *print_ptr = header_;
    while (print_ptr != nullptr) {
      std::cout << print_ptr->data << " -> ";
      print_ptr = print_ptr->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  void PushBack(const int& value) {
    if (header_ == nullptr) {
      header_ = CreatNode(value);
    } else {
      Node *push_ptr = header_;
      while (push_ptr->next != nullptr) {
        push_ptr = push_ptr->next;
      }
      Node *tmp_ptr = CreatNode(value);
      push_ptr->next = tmp_ptr;
    }
  }

  void Insert(const int& elem, const int& place) {
    if (Size() < place) {
      PushBack(elem);
      std::cout << "This position is shorter than the list size," \
                "insert this element by PushBack function" << std::endl;
    } else if (place == 0) {
      Node *tmp = CreatNode(elem);
      tmp->next = header_;
      header_ = tmp;
    } else {
      Node *tmp = CreatNode(elem);
      Node *cur_ptr = header_;
      for (int i = 1; i < place; ++i) {
        cur_ptr = cur_ptr->next;
      }
      Node *next_ptr = cur_ptr->next;
      cur_ptr->next = tmp;
      tmp->next = next_ptr;
    }
  }

  int Search(const int& elem){
    Node *search_ptr = header_;
    int count = 1;
    while (search_ptr != nullptr) {
      if (search_ptr->data == elem) {
        std::cout << "found this element" << std::endl;
        return count;
      }
      search_ptr = search_ptr->next;
      count++;
    }
    std::cout << "cannot found this element" << std::endl;
    return -1;
  }

  void Delete(const int& elem){
    Node *cur_ptr = header_;
    Node *pre_ptr = header_;
    if (Size() == 0) {
      std::cout << "list size is 0, cannot delete any element" << std::endl;
    } else if (cur_ptr->data == elem) {
      std::cout << "delete " << elem << " successed" << std::endl;
      header_ = cur_ptr->next;
    }
    if (cur_ptr->next == nullptr) {
      return;
    }
    cur_ptr = cur_ptr->next;
    while (cur_ptr->next != nullptr) {
      if (cur_ptr->data == elem ) {
        std::cout << "delete " << elem << " successed" << std::endl;
        pre_ptr->next = cur_ptr->next;
        cur_ptr = cur_ptr->next;
      } else {
        cur_ptr = cur_ptr->next;
        pre_ptr = pre_ptr->next;
      }
    }
    if (cur_ptr->data == elem) {
      std::cout << "delete " << elem << " successed" << std::endl;
      pre_ptr->next = nullptr;
    }
  }

  void Reverse(){
    Node *pre_ptr = header_;
    Node *cur_ptr = header_->next;
    Node *rear = header_;
    while (rear->next != nullptr) {
      rear = rear->next;
    }
    Recursion(pre_ptr, cur_ptr);
    header_->next = nullptr;
    header_ = rear;
  }

  int Size(){
    Node *ptr = header_;
    int count{};
    while (ptr != nullptr) {
      ptr = ptr->next;
      count++;
    }
    return count;
  }

 private:
  void Recursion(Node *pre_ptr, Node *cur_ptr){
    if (cur_ptr->next != nullptr) {
      Recursion(pre_ptr->next, cur_ptr->next);
    }
    cur_ptr->next = pre_ptr;
  }
  
  Node* CreatNode(int value) {
    Node *node = new Node();
    node->data = value;
    node->next = nullptr;
    return node;
  }
  void Distructor(Node *ptr) {
    if (ptr->next != nullptr) {
      Distructor(ptr->next);
    }
    // std::cout << "distruct element " << ptr->data << std::endl;
    delete ptr;
    ptr = nullptr;
  }

 private:
  Node *header_ = nullptr;

 public:
  ~LinkedList() {
    Distructor(header_);
    header_ = nullptr;
  }
};

int main() {
  LinkedList list;
  for (int i = 1; i <= 20; i++) {
    list.PushBack(i * 2);
  }
  list.Print();
  list.Insert(100, 10);
  list.Print();
  list.Delete(2);
  // list.Delete(40);
  list.Print();
  std::cout << "This list size is " << list.Size() << std::endl;
  
  std::cout << list.Search(2) << std::endl;
  list.Reverse();
  list.Print();

  return 0;
}

