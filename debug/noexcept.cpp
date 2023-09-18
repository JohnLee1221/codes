#include <iostream>
#include <vector>

void Derived(const int& a, const int& b) {
    if (b == 0) {
        throw std::runtime_error("Derived is 0");
    }
    std::cout << a / b << std::endl;
}

// void Foo() noexcept(noexcept(Derived(10, 1))) {
void Foo(const int& a, const int& b) noexcept(noexcept(Derived(a, b))) {
    // throw std::runtime_error("test");
    // try {
    //     Derived(a, b);
    // } catch (const std::runtime_error& err) {
    //     std::cerr << err.what() << std::endl;
    // }
    Derived(a, b);
}

void Test() {}

void Bar()  {
    Test();
}

int main() {
    try {
        Foo(10, 0);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }


    bool bool_1 = noexcept(Bar());
    std::cout << std::boolalpha << bool_1 << std::endl;    
    bool bool_2 = noexcept(true);
    std::cout << std::boolalpha << bool_2 << std::endl;    
    bool bool_3 = noexcept(false);
    std::cout << std::boolalpha << bool_3 << std::endl;    


    return 0;
}