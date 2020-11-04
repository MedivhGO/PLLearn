//
//  containerSize.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/14.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main()
{
    vector<int> v1 = {1,3,5,7,9,12};
    vector<int> v2 = {1,3,9};
    vector<int> v3 = {1,3,5,7};
    vector<int> v4 = {1,3,5,7,9,12};
    
    v1 < v2 ; //true
    v1 < v3 ; //false
    v1 == v4; //true
    v1 == v2; //false
    
    list<int> li = {1,3,9};
    
    if(li == v2)
        cout << "OK" << endl;
}
