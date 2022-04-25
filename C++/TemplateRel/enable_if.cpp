#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

int main()
{
    // is_integral<int>::value 是一个布尔值
    cout << std::is_integral<int>::value << endl;
    // 当enable_if 第一个模板参数为true时，type才有意义
    // 及为第二个模板参数
    typename std::enable_if<true, int>::type l = 10;
    //typename std::enable_if<false, int>::type l = 10;
    cout << l << endl;
}
