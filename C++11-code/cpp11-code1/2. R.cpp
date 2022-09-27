#include <iostream>
using namespace std;

#if 0
void printPath()
{
    string str = "D:\hello\world\test.text";
    cout << str << endl;
    string str1 = "D:\\hello\\world\\test.text";
    cout << str1 << endl;
    string str2 = R"(D:\hello\world\test.text)";
    cout << str2 << endl;
    cout << "game\r\nover" << endl;
    cout << R"(game\r\nover)" << endl;
}

void printHtml()
{
    string str = "<html>\
        <head>\
        <title>\
        海贼王\
        </title>\
        </head>\
        <body>\
        <p>\
        我是要成为海贼王的男人!!!\
        </p>\
        </body>\
        </html>";
    cout << str << endl;

    string str1 = u8R"111(<html>
        <head>
        <title>
        海贼王
        </title>
        </head>
        <body>
        <p>
        我是要成为海贼王的男人!!!
        </p>
        </body>
        </html>)111";
    cout << str1 << endl;

    // uR、UR 字符串
    u16string str2 = uR"(hello)";
    u32string str2 = UR"(hello)";
}

int main()
{
    printHtml();
	return 0;
}
#endif
