#include <type_traits>
#include <limits>
#include <cmath>
#include <iostream>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type //���߱��������Ǹ�������
equal(T lhs, T rhs)
{
    std::cout << "Int execute";
    return lhs == rhs;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type //���߱��������Ǹ�������
equal(T lhs, T rhs)
{
    std::cout << "Float execute";
    return std::abs(lhs - rhs) < 0.0001;
}


//int main()
//{
//    //ģ�庯�������Զ���ȡ���������ͣ�Template Argument Deduction)
//    equal(1, 2);
//    std::cout << std::endl;
//    equal(1.1, 1.1);
//}