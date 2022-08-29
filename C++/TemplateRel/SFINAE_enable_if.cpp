#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

template<bool, typename Enable = void>
struct my_enable_if {
};

template<typename T>
struct my_enable_if<true, T> {
    using type = T;
};

int main()
{
    // is_integral<int>::value 是一个布尔值
    cout << std::is_integral<int>::value << endl;
    // 当enable_if 第一个模板参数为true时，type才有意义
    // 及为第二个模板参数
    typename std::enable_if<true, int>::type l = 10;
    // typename std::enable_if<false, int>::type l = 10;
    cout << l << endl;
    
    typename my_enable_if<true, double>::type d = 3.14;
    // typename my_enable_if<false, double>::type dd = 3.14;
    
    // 全特化版本, 不存在 using type = T 这样的类型声明
    my_enable_if<false, float> t;
    
    cout << d << endl;

}
