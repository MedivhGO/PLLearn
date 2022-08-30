//
//  AssociativeContainerIterators.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/11/24.
//  Copyright © 2016年 ls. All rights reserved.
//  modify time 2022年8月30日23:18:34
//

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    set<int> iset = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    set<int>::iterator set_it = iset.begin();
    while (set_it != iset.end()) {
        //error keys in a set are read_only *set_it = 42;
        cout << *set_it << endl;
        set_it++;
    }
    //add element
    set<int> set2;
    set2.insert({ 1, 3, 5, 7, 1, 3, 5, 7 });
    for (auto x : set2) {
        cout << x << " ";
    }
    map<string, int> mapping;
    mapping.insert({"first", 1});
    mapping.insert(make_pair("second", 2));
    mapping.insert(pair<string, int>("third", 3));
    mapping.insert(map<string, int>::value_type("fourth", 4));
}
