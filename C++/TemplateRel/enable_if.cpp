#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

int main()
{
    // is_integral<int>::value ��һ������ֵ
    cout << std::is_integral<int>::value << endl;
    // ��enable_if ��һ��ģ�����Ϊtrueʱ��type��������
    // ��Ϊ�ڶ���ģ�����
    typename std::enable_if<true, int>::type l = 10;
    //typename std::enable_if<false, int>::type l = 10;
    cout << l << endl;
}
