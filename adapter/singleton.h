#ifndef ADAPTER_SINGLETON_H_
#define ADAPTER_SINGLETON_H_

class AdapterManager;

class Singleton {
 public:
  Singleton(Singleton& singletion) = delete;
  Singleton& operator=(Singleton& singletion) = delete;

  static AdapterManager* Instance() {
    return adapter_manager;
  }

 private:
  Singleton() = default;

  static AdapterManager *adapter_manager;
};

AdapterManager *Singleton::adapter_manager = nullptr;


#endif  // ADAPTER_SINGLETON_H_