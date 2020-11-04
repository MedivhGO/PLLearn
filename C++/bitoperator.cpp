//
//  bitoperator.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 2016/12/19.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <bitset>
using namespace std;
int count_one(int n) {
    int count = 0;
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}
void set() {
    bitset<32> bit(4);
    bitset<32> sample(1);
    bit |= ~(sample<<32);
    cout << bit << endl;
}
void clear() {
    bitset<32> bit(4);
    bit &= (1<<32);
    cout << bit <<endl;
}
void test() {
    bitset<32> bit(4);
    bitset<32> sample(1);
    
}
int main()
{
    set();
    clear();
    
    cout << (-3)%2 << endl; //负数的余数还是负数
}
