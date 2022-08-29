#include <utility>
#include <iostream>
using namespace std;

// 转发一个函数的参数给另一个函数,就像另一个函数直接调用一样
// 转发只对引用参数有意义, 完美转发只有万能引用有意义, 因为只有万能引用才会对传入参数是左值还是右值进行编码
// 完美转发允许我们保留 参数值的类型(lvalue,rvalue)和(const voliate)修饰符
// 完美转发一般分为两步 
// 1. 接受一个引用
// 2. 然后使用std::forward进行转发


template<typename T, typename U>
std::pair<T, U> make_pair_wrapper(T&& t, U&& u) // t和u是即将转发的引用, 他们被声明为X&& x的引用
{
    // 我们将这些参数转发给make_pair, 并保留参数的属性
    return std::make_pair(std::forward<T>(t), std::forward<U>(u));
    // 完美转发经常和可变模板参数一起使用
    // 方便将所有参数的信息保留转发
}

int main()
{

}