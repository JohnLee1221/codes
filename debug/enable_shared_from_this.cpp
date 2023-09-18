#include <iostream>
#include <vector>
#include <functional>
#include <memory>

class A : public std::enable_shared_from_this<A> {
 public:
  A(int data) : data_(data) {}
  void registerCallback() {
    std::weak_ptr<A> weak_ptr = shared_from_this();
    auto callback = [weak_ptr] {
      if (auto shared_ptr = weak_ptr.lock()) {
        std::cout << "Callback : data = " << shared_ptr->data_ << std::endl;
      } else {
        std::cout << "Callback A instance has been destroyed." << std::endl;
      }
    };
    callbacks_.push_back(callback);
  }

  void callCallback() {
    for (auto& callback : callbacks_) {
      callback();
    }
  }

 public:
  int data_;
 private:
  std::vector<std::function<void()>> callbacks_;
};

class B {
 public:
  B(std::shared_ptr<A> a) : a_(a) {}
  void doSomething() {
    std::shared_ptr<A> shared_ptr = a_->shared_from_this();
    std::cout << "B: A data = " << shared_ptr->data_ << std::endl;
  }

 private:
  std::shared_ptr<A> a_;
};

int main() {
  std::shared_ptr<A> ptr1 = std::make_shared<A>(100);
  ptr1->registerCallback();
  ptr1->callCallback();

  std::shared_ptr<A> ptr2 = std::make_shared<A> (200);
  B b(ptr2);
  b.doSomething();

  return 0;
}