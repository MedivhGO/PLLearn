//
//  mapinsert.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/11/25.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string,size_t> word_count;
    string word;
    while (cin>>word) {
        auto ret = word_count.insert({word,1});
        if(!ret.second) { //already in word_count
            ++ret.first->second;
        }
    }
    
    //multimap add element
    
    multimap<string,string> authors;
    authors.insert({"Barth,John","Sot-Weed Factor"});
    authors.insert({"Barth,John","Lost in the FunHouse"});
    /*
     the insert operation that takes a single element returns an iterator to the new element.
     */
}
