#include <utility>

// ת��һ�������Ĳ�������һ������,������һ������ֱ�ӵ���һ��

// ����ת���������Ǳ��� ����ֵ������(lvalue,rvalue)��(const voliate)���η�.

// ����ת��һ���Ϊ���� ����һ������,Ȼ��ʹ��std::forward����ת��

template<typename T, typename U>
std::pair<T, U> make_pair_wrapper(T&& t, U&& u) // t��u�Ǽ���ת��������,��Ϊ���Ǳ�����Ϊ X&& x������
{
	return std::make_pair(std::forward<T>(t),
		std::forward<U>(u)); // ���ǽ���Щ����ת����make_pair,ʹ����Щԭʼ����ֵ���ʽmove into pair
}

// ����ת�������Ϳɱ�ģ�����һ��ʹ��

int main()
{

}