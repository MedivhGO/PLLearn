//
//  addElem.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/14.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
int main()
{
    list<int> ilist;
    for(size_t ix = 0;ix!=4;++ix)
    {
        ilist.push_front(ix);
    }//3 2 1 0
    
    list<string> slist;
    list<string>::iterator iter = slist.begin();
    
    vector<string> svec;
    slist.insert(slist.begin(),"hello!");
    svec.insert(svec.begin(),"Hello!");
    
    cout << slist.front()<<endl;
    cout << svec[0] <<endl;
    
    svec.insert(svec.end(),10,"Anna");
    
    vector<string> v = {"quasi","simba","frollo","scar"};
    
    slist.insert(slist.begin(),v.end()-2,v.end());//以迭代器为后两位参数
    //insert 在插入完成后返回插入的第一个元素的迭代器，如果插入为空，则返回第一个参数
    list<string> lst;
    string word;
    auto iter1 = lst.begin();
    while(cin>>word)
    {
        iter1 = lst.insert(iter1,word); //same as calling push_front
        
    }
    
    
}
