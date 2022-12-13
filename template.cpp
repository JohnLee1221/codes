#include <typeinfo>
#include <cxxabi.h>
#include <iostream>
#include <vector>

//将gcc编译出来的类型翻译为真实的类型
const char* GetRealType(const char* p_szSingleType)
{
    const char* szRealType = abi::__cxa_demangle(p_szSingleType, nullptr, nullptr, nullptr);
    return szRealType;
}

//这里的func是一个模板模板形参
// template<template<typename, typename> class func, typename tp, typename alloc = std::allocator<tp> >
template<template<typename> class func, typename tp>
struct temp_traits
{
    // using type = func<tp, alloc>;
    using type = func<tp>;
    type tt;//根据模板类型定义一个成员变量
};

int main()
{
    // temp_traits<template<std::vector,std::allocator<std::vector<int>>>
    // temp_traits<std::vector, int> _traits;
    temp_traits<std::vector<int>> _traits;
    //获取结构体字段tt的类型
    const std::type_info &info = typeid(_traits.tt);
    std::cout << GetRealType(info.name()) << std::endl;
    return 0;
}