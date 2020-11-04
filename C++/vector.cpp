//
//  vector.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/26.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    vector<int> ivec(10);//对于内置基本数据类型整型数据默认初始化为0；string类型默认为空
    vector<int> ivec2(ivec);
    //可以使用同一类型的vector初始化另一个vector
    for(auto i : ivec)
    {
        cout << i <<endl;
    }
    //列表初始值还是元素数量？
    vector<int> v1(10);//初始化10个元素的vector
    vector<int> v2{10};//列表初始化一个元素10
    
    vector<int> v3(10,1);//指定了元素的值和个数
    vector<int> v4{10,1};//列表初始化10，1。两个元素
    
    //另一种情况，当尝试使用花括号进行列表初始化，如果无法完成，编译器会进行（）一样的初始化。
    auto it4 = v4.cbegin();
    //返回const_interator类型，只能通过该迭代器进行读操作，不能够写入。
    
    
}
