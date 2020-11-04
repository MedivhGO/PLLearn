//
//  setmap.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/11/24.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main()
{
    //the keys in a map or a set must be unique
    map<string,string> authors = {
        {"Joyce","James"},
        {"Austen","Jane"},
        {"Dickens","Charles"}
    };
    for (auto x : authors) {
        cout << x.first << "," << x.second <<endl;
    }
    
    vector<int> ivec;
    
    for(vector<int>::size_type i=0;i!=10;++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(),ivec.cend());
    multiset<int> miset(ivec.cbegin(),ivec.cend());
    
    cout << ivec.size() <<endl;
    cout << iset.size() <<endl; //have duplicate element
    cout << miset.size() << endl; //have unique element
    
}
