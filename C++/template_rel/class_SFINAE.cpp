#include <type_traits>
#include <iostream>
template <typename T, typename Enable = void>
class foo;

// SFINAE substitution failure is not an error 
// 使用一些给定的参数实例化模板的失败的状态不会导致错误,只是简单的放弃实例化


// 使用std::enable_if强制 仅仅实例化特定的类型参数 
template <typename T>
class foo<T, typename std::enable_if<std::is_integral<T>::value>::type>
{
public:
    foo() {
        std::cout << "Integer";
    }
}; // 


template <typename T>
class foo<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
{
public:
    foo() {
        std::cout << "Float";
    }
}; // 特化模板2

//int main()
//{
//    foo<int> fi;
//    std::cout << std::endl;
//    foo<float> ff;
//}
