//
//  dequeString.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/16.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
    string word;
    deque<string> sdeq;
    while(cin>>word)
    {
        if(word == "stop")
            break;
        sdeq.push_back(word);
    }
    deque<string>::iterator iter;
    for(iter = sdeq.begin();iter!=sdeq.end();iter++)
    {
        cout << *iter << endl;
    }
    
}
