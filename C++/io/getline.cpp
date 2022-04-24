//
//  getline.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/26.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string line;
    while(getline(cin,line)) {
        cout << line << endl; // 读入换行符但并不存储
    }
    return 0;
}
