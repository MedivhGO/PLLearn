//
//  pair.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/11/24.
//  Copyright © 2016年 ls. All rights reserved.
//
#include <utility>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
int main()
{
    pair<string,string>  authot{"James","Joyce"};
    //unlike other library types,the data members of pair are public
    //these members are named first and second respectively
    set<string>::value_type v1; //string
    set<string>::key_type v2; //string
    map<string,int>::value_type v3; //int
    map<string,int>::key_type v4; //string
    map<string,int>::mapped_type v5;
    //Only the map types ( unordered_map, unordered_multimap, multimap, and map) define
    //mapped_type .
    
    	
}
