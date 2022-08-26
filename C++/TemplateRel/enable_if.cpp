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
    // is_integral<int>::value ��һ������ֵ
    cout << std::is_integral<int>::value << endl;
    // ��enable_if ��һ��ģ�����Ϊtrueʱ��type��������
    // ��Ϊ�ڶ���ģ�����
    typename std::enable_if<true, int>::type l = 10;
    // typename std::enable_if<false, int>::type l = 10;
    cout << l << endl;
    
    typename my_enable_if<true, double>::type d = 3.14;
    // typename my_enable_if<false, double>::type dd = 3.14;
    
    // ȫ�ػ��汾, ������ using type = T ��������������
    my_enable_if<false, float> t;
    
    cout << d << endl;

}
