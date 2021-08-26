//
//  listString.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/16.
//  Copyright © 2016年 ls. All rights reserved.
//
#include <list>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    list<string> slist;
    string word;
    while(cin>>word)
    {
        if(word == "stop")
            break;
        slist.push_back(word);
    }
    list<string>::iterator iter;
    for(iter = slist.begin();iter!=slist.end();iter++)
    {
        cout << *iter <<endl;
    }
    
}
