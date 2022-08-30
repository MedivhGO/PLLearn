#include <iostream>
#include <stdio.h>
using namespace std;
class String {
public:
    String(const char *str=nullptr);//一个参数的构造函数，当没有提供初始值时就采用默认的参数
    String(const String& other);//拷贝构造函数
    String& operator=(const String& other); //重载赋值运算符
    virtual ~String(); //虚析构函数，释放s_data指向的指针
private:
    char* s_data;
};
String::String(const char* str) {//空实参初始化的时候需要将s_data指向一个空字符。用一个字符数组初始化时，复制该数组。
    if (str==nullptr) {
        s_data = new char[1];
        *s_data = '\0';
    } else {
        int len = strlen(str);
        s_data = new char[len+1];
        strcpy(s_data,str);
    }
}
String::String(const String& other) {//拷贝构造函数
    int len = strlen(other.s_data);
    s_data = new char[len+1];
    strcpy(s_data, other.s_data);
}
String& String::operator=(const String& other) {
    if (this == &other) return *this; //防止自赋值
    delete[] s_data;//删除原来string s_data的内存空间
    int len =strlen(other.s_data); //求右侧串长
    s_data = new char[len+1];//给左侧申请新的空间
    strcpy(s_data, other.s_data);//赋值
    return *this;//返回
}
String::~String() {
    delete[] s_data;
}

