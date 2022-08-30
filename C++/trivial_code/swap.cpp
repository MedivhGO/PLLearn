//
//  swap.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/13.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void print(vector<string> data) {
    for (auto x : data) {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> svec1{"3", "2", "1"};
    vector<string> svec2{"1", "2", "3"};
    print(svec1);
    print(svec2);
    // 交换两个容器内容的操作保证会很快，元素本身并没有交换，swap只是交换了两个容器的内部数据结构。
    // 除了string外，交换后iterator reference，pointers都不会改变
    // 最好使用非成员函数版本的swap
    swap(svec1, svec2);
    print(svec1);
    print(svec2);

    vector<string> svec;
    list<const char*> ls = {"a", "abc" ,"abcdefgg"};

    svec.assign(ls.begin(), ls.end());
    for (auto x : svec) {
        cout << x << " ";
    }
    cout << endl;
}