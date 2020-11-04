//
//  iterator.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/11.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;
/*
    对于string和vector的迭代器来说，除了判断是否相等，还能使用关系运算符（<,<=,>,>=）对其进行比较
    其他容器不能使用关系运算符
 
 
 */
int main()
{
    list<int> lst1;
    
    list<int>::iterator iter1 = lst1.begin(),iter2 = lst1.end();
    
    while(iter1 !=  iter2)
    {
        cout << "aaa"<<endl;
    }
    vector<int> vec1;
    vector<int>::iterator viter1 = vec1.begin(),viter2 = vec1.end();
    while(viter1 < viter2)
    {
        cout << "aaaaaa" << endl;
    }
}
