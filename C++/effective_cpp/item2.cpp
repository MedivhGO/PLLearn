//
// Created by Allen on 2018/10/23.
//
#include <string>
#include <iostream>
using namespace std;

const char* const authorName = "Scott Meyer";
const string strauthorName("Scott Meyer");

//class 专属常量，常量的作用域限制在class内，必须使他成为class一个成员，确保只要一份拷贝，声明成static
class GamePlayer
{
    static const int NumTurns = 5; //声明非定义如果使class并且又是static可以例外，只声明
    int scores[NumTurns];
};
//我们无法利用#define为class创建专属常量，因为他不重视作用域
//可以用枚举替代
class Gameplayer
{
private:
    enum {numTurns = 5};
    int scores[numTurns]; //The enum hack is a fundamental technique of TMP(Item 48)
};

// enum hack法则，他比较像#define, 不能取地址

/********Part2 ********/
//用inline替换带参的宏
//但是函数调用有一个保存现场和恢复现场的过程（本质是栈的压入和弹出），频繁的调用会导致性能的低下
//解决办法是在函数前面加上inline关键字
template <class T>
T square(const T& v)
{
    return v*v;
}
template <class T>
inline T square_inline(const T& v)
{
    return v*v;
}

