#include <stdio.h>
#define SQUARE(x) (x)*(x)
#define DOUBLE(x) ((x)+(x))
#define PI 3.14
#if defined(PI)

#endif

#ifndef PP
    #define PP 1024
#endif


/*
  预处理器的主要任务
    1.删除注释
    2.插入被#include指令包含的文件内容
    3.定义和替换由#define定义的符号
    4.以及确定代码的部分内容是否应该根据一些条件编译指令进行编译
 */

/*
 由预处理器定义的一些符号
 */
int preprodef() {
    printf("%s\n",__FILE__);
    printf("%d\n",__LINE__);
    printf("%s\n",__DATE__);
    printf("%s\n",__TIME__);
    printf("%d\n",__STDC__);
    return 0;
}
/*
  #define 定义了一个机制，允许把参数替换到文本中，这种实现通常称为宏（macro）或定义宏
 
    格式
        #define name(parameter-list) stuff
 
    使用#undef解除一个宏定义
    格式
        #undef name
 
 */

/*
    条件编译
        #if constant-expression
                statement
        #endif
 
       常量表达式由预处理器进行求值，如果它的值是非零值，为真。那么statements部分就被正常编译，否则预处理器就安静的删除他们。
 
        #if constant-expression
                statement1
        #elif constant-expression
                statement2
        #elif constant-expression
                statement3
        #else
                statement4
        #endif
 
    是否被定义
        测试一个符号是否已被定义也是可能的。
        
        #if defined(symbol)
        #ifdef symbol
 
        #if !define(symbol)
        #ifndef symbol
 
 */


int main()
{
    
    preprodef();
    int a = 5;
    printf("%d\n",SQUARE(a+1));
    printf("%d\n",10*DOUBLE(a));
    printf("%d\n",PP);
}
