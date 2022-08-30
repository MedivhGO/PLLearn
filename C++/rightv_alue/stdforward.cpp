#include "Test.h"
#include <iostream>
using namespace std;

class Foo {
public:
    Foo() {
        cout << "Create a Foo object" << endl;
    }
};

void func_inner(Foo& foo) {
    cout << "Call left_value inner func" << endl;
}

void func_inner(Foo&& foo) {
    cout << "Call right_value inner func" << endl;
}

template <typename T>
void func(T&& param) {
    //func_inner(param); // 函数参数, 统一为左值
    func_inner(std::forward<T>(param)); // 转发, 保留param型别属性
    // func_inner(my_forward<T>(param));
}

// 当func的传入参数是左值时
// 模板函数实例化出如下函数签名
/*
    void func(Foo& && param); // 引用折叠
    void func(Foo& param);

    引用折叠规则
    两个都是右值引用, 则结果为右值引用
    否则为左值引用
*/

template <typename T>
T&& my_forward(typename remove_reference<T>::type& param) {
    return static_cast<T&&>(param);
}

/*
    如果对func传入左值, 通用引用, 会得到Foo&, 传给my_forward函数
    则my_forward函数实例化为
        Foo& my_forward(Foo& param) {
            return static_cast<Foo&>(param);
        }
    得到一个左值引用
    如果对func传入右值, 通用引用, 会得到Foo, 传给my_forward函数
    则my_forward函数实例化为
        Foo&& my_forward(Foo& param) {
            return static_cast<Foo&&>(param);
        }
    得到一个右值引用

    由此可见, forward的函数当参数是右值时, 会把该参数右值属性保留
*/


Foo Get_Foo_Object() {
    return Foo();
}

int main()
{    
    Foo left_foo; // 左值

    func(left_foo);
    func(Get_Foo_Object());

    return 0;
}
