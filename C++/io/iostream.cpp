//
//  iostream.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/29.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    cin.tie(&cout);
    //old_tie 得到指向当前关联到cin的流（如果有的话）
    ostream* old_tie = cin.tie(nullptr);

    cin.tie(&cerr);
    cin.tie(old_tie);
}
