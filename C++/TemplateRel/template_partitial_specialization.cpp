#include <iostream>
using namespace std;

namespace templateTest{

template<typename T>
class iterator_traits
{
public:
    iterator_traits()
    {
        cout << "模版泛化" << endl;
    }
    ~iterator_traits() {}
};

template<typename T>
class iterator_traits<T*>
{
public:
    iterator_traits()
    {
        cout << "模版偏特化, 特化常规指针" << endl;
    }
    ~iterator_traits() {}
};
    
template <typename T>
class iterator_traits<const T*>
{
public:
    iterator_traits()
    {
        cout << "模版偏特化, 特化const指针" << endl;
    }
    ~iterator_traits() {}
};

template<>
class iterator_traits<int>
{
public:
    iterator_traits()
    {
        cout << "模版全特化int类型" << endl;
    }
    ~iterator_traits() {}
};

template <class U,class T>
class Test
{
public:
    Test()
    {
        cout << "Test 泛化" << endl;
    }
};

template <class T>
class Test<int, T>
{
public:
    Test()
    {
        cout << "Test 偏特化" << endl;
    }
};

template<>
class Test<int, char>
{
public:
    Test()
    {
        cout << "Test 全特化" << endl;
    }
};

template<typename T>
void max(const T& t1,const T& t2)
{
    cout << "函数模版泛化" << endl;
}
template<>
void max<int>(const int& t1,const int& t2)
{
    cout << "模版函数特化" << endl;
}

}  // namesapce templateTest

int main()
{
    templateTest::max(1.2, 1.3); // 函数模版泛化
}