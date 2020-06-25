//
//  sstream.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/10/6.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct PersonInfo
{
    string name;
    vector<string> phones;
};
int main()
{
    string line,word;
    vector<PersonInfo> people;
    while(getline(cin,line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while(record>>word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
}
int fun()
{
    for(const auto &entry:people)
    {
        ostringstream formatted,badNUms;
        for(const auto &nums:entry.phones)
        {
            if(!valid(nums)){
                badNums << " " << nums;
            }
            else{
                formatted << " " <<format(nums);
            }
        }
        if(badNums.str().empty())
            os << entry.name << " "
            << formatted.str() <<endl;
        else
            cerr << "input error:" << entry.name
            << "invalid number(s)" << badNUms.str()<<endl;
    }
}
