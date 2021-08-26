//
//  iohead.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/28.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
    auto old_state = cin.rdstate();
    cin.clear(cin.rdstate()&~cin.failbit&~cin.badbit);
    cout << cin.rdstate()<<endl;
    cout << "Hi!"<<endl;
    cout << "Hi!"<<flush;
    cout << "Hi!"<<ends;
    cout << "abc";
}
