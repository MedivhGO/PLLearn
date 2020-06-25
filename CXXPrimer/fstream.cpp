//
//  fstream.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/29.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    
    
    //fstream f;
    string s = "./File";
    f.open(s,ofstream::app);//open指定文件模式；
    ifstream in(s);
    ofstream out;
    out.open("./outfile");
    
    for(auto p = argv+1;p!=argv+argc;++p)
    {
        ifstream input(*p);
        if(input)
        {
            process(input);
        }
        else{
            cerr << "couldn't open" + string(*p);
        }
    }
    ofstream out2("file1",ofstream::out);
    ofstream out3("file1",ofstream::out|ofstream::trunc);
    
    ofstream app("file2",ofstream::app);
    ofstream app2("file2",ofstream::out|ofstream::app);
    
}
