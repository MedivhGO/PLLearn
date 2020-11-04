//
//  array.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/13.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main()
{
    array<int, 42> a; //随机赋值
    for(auto x : a)
        cout << x <<" ";
    cout << endl;
    array<int,10> a1 = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> a2 = {42};
    
    
    array<int,10> digits ={0,1,2,3,4,5,6,7,8,9};
    array<int,10> copy = digits;
    
    for(auto x : copy)
        cout << x << " " ;
    cout << endl;
    //c1,c2 必须有相同的类型
    swap(a1,a2);
    
    for(auto x : a1)
    {
        cout << x << " ";
    }
    cout << endl;
    for(auto x : a2)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> vec1 = {1,1,1,1,11,1};
    vec1.assign(10,2);//assign 允许我们从一个不同但相容的类型赋值，或者从容器的一个子序列赋值(并不能指向调用assign的顺序容器)
    vector<int>::iterator it = vec1.begin(),ite = vec1.end();
    for(;it!=ite;it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    list<string> names;
    vector<const char*> oldstyle;
    names.assign(oldstyle.cbegin(),oldstyle.cend());
    
}
