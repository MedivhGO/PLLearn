//
//  cast.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/27.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
using namespace std;
// cast-name<type>(expression)
//cast-name static_cast,dynamic_cast,const_cast,reinterpret_cast
int main()
{
    //static_cast 把较大的数据类型，转换为较小的数据类型，不在乎潜在的精度损失。
    int i=2,j=3;
    int d;
    double slope = static_cast<double>(j)/i;
    //static_cast 也可以找回存在于void*的指针
    void *p = &d;
    double *dp = static_cast<double*>(p);
    
    //const_cast 只能改变运算对象的底层const
    const char* pc;
    char* t = const_cast<char*>(pc);//指针改变指向的对象，由原来的const类型变为普通类型。
   
    //reinterpret_cast 通常为运算对象的位模式提供较低层次上的重新解释
    int *ip;
    char* pc = reinterpret_cast<char*>(ip);//编译器不会报错，但这么做十分危险
    
    
}
