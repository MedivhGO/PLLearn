//
//  capacity.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 2016/11/28.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> ivec;
    cout << "ivec size: " << ivec.size() <<endl;
    cout << "ivec capacity: " << ivec.capacity() << endl;
    
    ivec.reserve(50);
    cout << "ivec capacity: " << ivec.capacity() << endl;
    
    ivec.resize(100);
    cout << "ivec size: " << ivec.size() <<endl;
    cout << "ivec capacity: " << ivec.capacity() << endl;
    
    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(3);
    
    ivec.resize(100);
    cout << "ivec size: " << ivec.size() <<endl;
    cout << "ivec capacity: " << ivec.capacity() << endl;
    
    ivec.shrink_to_fit();
    
    cout << "ivec size: " << ivec.size() <<endl;
    cout << "ivec capacity: " << ivec.capacity() << endl;
}
