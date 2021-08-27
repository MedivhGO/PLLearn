#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
class Sales_data {};
template <typename T>
int compare(const T& v1, const T& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template <unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M])
{
    return strcmp(p1, p2);
} //使用非类型参数比较数组引用
//solution 16.4

template<typename InputIter,typename T>
InputIter myfind(const InputIter begin, const InputIter end, const T& value)
{
    for (InputIter iter = begin; iter != end; iter++)
    {
        if (*iter == value)
        {
            return iter;
        }
    }
}


// solution 16.5
template <typename T, unsigned N>
void print(const T(&arr)[N])
{
    for (auto elem : arr) {
        cout << elem << endl;
    }
}
// solution 16.6

template <typename T, unsigned N>
T* begin(const T(&arr)[N])
{
    return arr;
}

template <typename T, unsigned N>
T* end(const T(&arr)[N])
{
    return arr + N;
}


//solution 16.7 编写一个能够返回给定数组长度的模板函数

template <typename T, unsigned N>
constexpr unsigned GetLen(const T(&arr)[N])
{
    return N;
}


int main(int argc, char* argv[]) {
    cout << compare(1,0) << endl; //推断出的模板参数为我们实例化一个特定版本的函数
    cout << compare("hi", "mom") << endl;//编译器会使用字面值常量大小来代替N和M,从而实例化模板.
    //编译器会在一个字符串字面常量的末尾插入一个空字符串作为终结符.
    //所以编译器实例化出如下的版本
    // int compare(const char (&p1)[3],const char (&p2)[4])
    Sales_data sd1, sd2;
    compare(sd1, sd2);
    char charr[] = { 'a','b','c','d' };
    int  intarr[] = { 1,2,3,4,5 };


    vector<int> ivec{ 1,2,3,4,5,6 };
    list<string> ilst{ "abc","bdc","aaa" };

    print(charr);
    cout << "*************" << endl;
    print(intarr);
    cout << "*************" << endl;
    cout << GetLen(charr) << endl;
    cout << "*************" << endl;
    cout << *(myfind(ivec.cbegin(), ivec.cend(),4))<<endl;
    cout << "*************" << endl;
    cout << *(myfind(ilst.cbegin(), ilst.cend(),"aaa"));
}
