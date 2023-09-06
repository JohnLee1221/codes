#include <iostream>
#include <queue>
#include <functional>
#include <memory>

void GeneralEvent() {
  std::cout << "This is a general event" << std::endl;
}

void ImportantEvent() {
  std::cout << "This is a important event" << std::endl;
}

void EmergencyEvent() {
  std::cout << "This is a emergency event" << std::endl;
}

using Task = std::function<void()>;
using TaskQueue = std::queue<Task>;

class Singleton {
 public:
  Singleton(const Singleton& singleton) = delete;
  Singleton& operator=(const Singleton& singleton) = delete;

  static std::shared_ptr<Singleton> GetInstance() {
    return singleton_;
  }

  void AddTask(const Task& task) {
    task_queue_.push(task);
    std::cout << "Add event successed" << std::endl;
  }

  void RunTask() {
    while (!task_queue_.empty()) {
      auto f = task_queue_.front();
      f();
      task_queue_.pop();
    }
  }

 private:
  Singleton() = default;
  static std::shared_ptr<Singleton> singleton_;
  TaskQueue task_queue_;
};

std::shared_ptr<Singleton> Singleton::singleton_(new Singleton);

int main() {
  Singleton::GetInstance()->AddTask(ImportantEvent);
  Singleton::GetInstance()->AddTask(GeneralEvent);
  Singleton::GetInstance()->AddTask(EmergencyEvent);

  Singleton::GetInstance()->RunTask();
  return 0;
}