// R.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

#if 0
int main()
{
    char normal[] = "hello";
    char normal_1[] = "你好哇";
    cout << normal << ", size: " << sizeof(normal) << endl;
    cout << normal_1 << ", size: " << sizeof(normal_1) << endl;

    cout << "******** UTF-8 ********:" << endl;
    char utf8[] = u8"hello";
    cout << utf8 << ", size: " << sizeof(utf8) << endl;
    char utf8_1[] = u8"你好哇";
    cout << utf8_1 << ", size: " << sizeof(utf8_1) << endl;

    cout << "******** UTF-16 ********:" << endl;
    char16_t utf16[] = u"hello";
    cout << utf16 << ", size: " << sizeof(utf16) << endl;
    char16_t utf16_1[] = u"你好哇";
    cout << utf16_1 << ", size: " << sizeof(utf16_1) << endl;


    cout << "******** UTF-32 ********:" << endl;
    char32_t utf32[] = U"hello";
    cout << utf32 << ", size: " << sizeof(utf32) << endl;
    char32_t utf32_1[] = U"你好哇";
    cout << utf32_1 << ", size: " << sizeof(utf32_1) << endl;
    // 2. 数组对应的字符串类型
    string str = u8"hello";
    u16string str1 = u"nihao";
    u32string str1 = U"nihao";
     
    return 0;
}
#endif
