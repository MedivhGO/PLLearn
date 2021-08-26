#include <utility>

// 转发一个函数的参数给另一个函数,就像另一个函数直接调用一样

// 完美转发允许我们保留 参数值的类型(lvalue,rvalue)和(const voliate)修饰符.

// 完美转发一般分为两步 接受一个引用,然后使用std::forward进行转发

template<typename T, typename U>
std::pair<T, U> make_pair_wrapper(T&& t, U&& u) // t和u是即将转发的引用,因为他们被声明为 X&& x的引用
{
	return std::make_pair(std::forward<T>(t),
		std::forward<U>(u)); // 我们讲这些参数转发给make_pair,使得这些原始的右值表达式move into pair
}

// 完美转发经常和可变模板参数一起使用

int main()
{

}