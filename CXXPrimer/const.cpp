//
//  const.cpp
//  Cppprimer
//
//  Created by 李敬琪 on 16/9/24.
//  Copyright © 2016年 ls. All rights reserved.
/********************************/
//  const 与 常量引用
#include <iostream>
using namespace std;
extern const int bufSize = 1024;
int main()
{
    const int size = 512;
    const int ival = 1024;

    const int &refval = ival;
    /************************************************************************/
    int i = 42;
    
    const int &r = 42;
    const int &r2 = r+i;
    
    double dval = 3.14; //会创建一个临时的const变量，与常量引用绑定，由于此时变量引用到一个临时的非dval变量，所以若ri不是
    //常量引用，则会造成临时变量被更改，这是非法的。
    const int &ri = dval;
    /***********************************************************************/
    //对于引用的对象本身是否是const并未做限定，及时不能通过常量引用更改其值，也可以通过其他方式更改变量的值
    int &r1 = i;
    const int &r3 = i;
    r1 =0 ;
   // r3 = 0;
    
    
}
