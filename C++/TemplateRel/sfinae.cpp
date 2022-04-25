#include <bits/stdc++.h>
using namespace std;

class Buffer 
{
public:
    void append(char c, size_t n = 1); // 1
    void append(const char* s, size_t n); // 2
    
    template<typename Iter>
    void append(Iter bp, Iter ep); // 3
    
    // Ϊ�˷�ֹƥ�����ģ�庯��
    // ͨ���õڶ���ģ������Ƶ�ʧ������ֹƥ��
//    template<typename Iter, typename T = void>
//    void append(Iter bp, Iter ep); // 4
    
    template<
        typename Iter, 
        typename = typename std::enable_if<!std::is_integral<Iter>::value>::type
    >
    void append(Iter bp, Iter ep); // 5
    
    // Ҳ��������д
    template<typename Iter,
        typename std::enable_if<!std::is_integral<Iter>::value, int>::type = 0
    >
    void append(Iter bp, Iter ep); // 6
};

int main()
{
    int ch = ::getchar();
    if (ch == EOF) {
        return 1;
    }
    
    Buffer buff;
    buff.append(ch, 10); // int, int ����� 3
    
}
