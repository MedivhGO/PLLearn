//
//  func_back.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/11/24.
//  Copyright © 2016年 ls. All rights reserved.
//

#include <vector>
#include <iostream>

int main()
{
    std::vector<char> letters {'o', 'm', 'g', 'w', 't', 'f'};
    if (!letters.empty()) {
        std::cout << "The last character is: " << letters.back() << '\n'; //back() return the last value in the vector or
        //Calling back on an empty container is undefined.
    }
}
