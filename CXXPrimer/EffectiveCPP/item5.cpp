//
// Created by Allen on 2018/10/23.
//

#include <iostream>
using namespace std;

class Stub
{
public:
    int& ival;
    Stub(int i);
    //Stub&operator=(const Stub& rhs);

};
Stub::Stub(int i) : ival(i){ }
//Stub&  Stub:: operator=(const Stub& rhs)
//{
//    this->ival = rhs.ival;
//    return *this;
//}
//int main()
//{
//    int a = 10, b = 20;
//    Stub s2(a);
//    Stub s1(b);
//
//    s1 = s2;
//}

/*
 *
 * C++ 不保证 生成一个 隐式的赋值运算符
 *
 *  a). 类中包含引用成员
 *  b). 类中包含常量成员
 *  c). 子类继承的父类的中声明了私有的赋值运算符
 * */