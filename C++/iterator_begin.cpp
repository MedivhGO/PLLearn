//
//  iterator_begin.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/11.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>
using namespace std;
int main()
{
    list<string> a;
    list<string>::iterator it5 = a.begin();
    list<string>::const_iterator it6 = a.begin();
    
    auto it7 = a.begin();
    auto it8 = a.cbegin();
    vector<int> v1;
    const vector<int> v2;
    
    auto it1 = v1.begin();
    auto it2 = v2.begin();//当与auto结合时，获得迭代器的类型依赖于容器类型
    //此处it2的类型是const_iterator类型
    
    //如果使用cbegin 那么获得的就是const_iterator
    auto it3 = v1.cbegin();
    auto it4 = v2.cbegin();
    
}
