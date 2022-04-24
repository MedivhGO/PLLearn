#include <type_traits>
#include <limits>
#include <cmath>
#include <iostream>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type //告诉编译器这是个类型名
equal(T lhs, T rhs)
{
    std::cout << "Int execute";
    return lhs == rhs;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type //告诉编译器这是个类型名
equal(T lhs, T rhs)
{
    std::cout << "Float execute";
    return std::abs(lhs - rhs) < 0.0001;
}


//int main()
//{
//    //模板函数可以自动抽取参数的类型（Template Argument Deduction)
//    equal(1, 2);
//    std::cout << std::endl;
//    equal(1.1, 1.1);
//}