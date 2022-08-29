#include <bits/stdc++.h>
using namespace std;

class Buffer 
{
public:
    void append(char c, size_t n = 1); // 1
    void append(const char* s, size_t n); // 2

    template<typename Iter>
    void append(Iter bp, Iter ep); // 3

    // 为了防止匹配这个模板函数
    // 通过让第二个模板参数推导失败来阻止匹配
    // template<typename Iter, typename T = void>
    // void append(Iter bp, Iter ep); // 4

    template<
        typename Iter, 
        typename = typename std::enable_if<!std::is_integral<Iter>::value>::type
    >
    void append(Iter bp, Iter ep); // 5
    
    // 也可以这样写
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
    buff.append(ch, 10); // int, int 会调用 3

}
