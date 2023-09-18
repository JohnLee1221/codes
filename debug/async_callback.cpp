#include <iostream>
#include <thread>
#include <functional>
#include <chrono>

// 定义一个回调函数类型
using CallbackFunction = std::function<void()>;

// 模拟一个耗时的异步操作
void AsyncOperation(CallbackFunction callback) {
    std::cout << "Start async operation..." << std::endl;
    // 模拟耗时操作，这里使用 sleep 来代替
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Async operation completed." << std::endl;

    // 操作完成后调用回调函数通知主线程
    callback();
}

// 回调函数，在异步操作完成后被调用
void OnAsyncOperationComplete() {
    std::cout << "Received notification: Async operation is complete." << std::endl;
}

int main() {
    std::cout << "Main thread: Starting async operation..." << std::endl;

    // 启动异步线程执行耗时操作，并在完成后通过回调函数通知主线程
    std::thread asyncThread(AsyncOperation, OnAsyncOperationComplete);

    // 主线程继续执行其他操作
    std::cout << "Main thread: Continue doing other tasks." << std::endl;

    // 等待异步线程执行完成
    asyncThread.join();

    std::cout << "Main thread: Exiting program." << std::endl;
    return 0;
}
