//
//  returnVec.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/18.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> fun()
{
    vector<int> vec;
    vec.push_back(1);
    return vec;
}
int main()
{
    vector<int> ivec;
    ivec = fun();
    cout << ivec.size();
}
