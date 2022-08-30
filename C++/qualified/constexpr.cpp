//
//  constexpr.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/26.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    constexpr int mf = 20;
    constexpr int limit = mf+1;
    //constexpr int sz = size();仅当size（）函数为constexpr函数时才是常量表达式
    cout << mf <<endl;

    int null = 0;
    int *p = &null;
}
