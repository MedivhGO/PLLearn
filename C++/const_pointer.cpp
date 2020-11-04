//
//  const_pointer.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/24.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
     const double pi = 3.1415;
    double var = 111;
    const double & r2 = var;
    const int *p;
    cout << r2 << endl;
    
    //double* ptr = &pi; 非法，会造成通过指针修改指向的值
    const double* cptr = &pi;
   // cptr = &var;
    //上面这种情况和 常量引用 类似

    int errNumb = 0;
    int* const curErr = &errNumb;
    const double *const pip = &pi;
    cout << *pip<<endl;
}
