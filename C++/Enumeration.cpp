#include <iostream>
using namespace std;
int main()
{
    //枚举类型 使我们可以将一组整型常量组织在一起，和类一样，每个枚举类型定义了一种新型的类型。枚举属于字面值常量类型。
    enum color {red,green,yellow};
    enum class peppers {red,yellow,green};
    
    color eyes = green;
    peppers p  = peppers::green;
    
    enum class intTypes {
        charTyp = 8, shortTyp = 16,intTyp = 16,
        longTyp = 32, long_longTyp = 64
    };
    
    cout << eyes << endl;
    
    int i = color::green;
    // int j = peppers::red 限定作用域的枚举类型不会进行隐式的转换。
    cout << i << endl;
    
    
    //指定枚举成员的类型
    enum intValues : unsigned long long {
        charTyp = 255,shortTyp = 65535, intTyp = 65535,
        longTyp = 4294967295UL,
        long_longTyp = 18446744073709551615ULL
    };
    
    
    //枚举类型的前置声明
    enum intValues : unsigned long long;
    enum class open_mode;
    
    
    //枚举类型做形参只能使用枚举类型对象，或者枚举成员作为实参。
    
    //整形做形参，我们可以将一个不限定作用域的枚举类型对象或者枚举成员作为参数传给形参。
    
    enum Tokens {INLINE = 128, VIRTUAL = 129};
    
    void newf(unsigned char);
    void newf(int);
    
    unsigned char uc = VIRTUAL;
   // newf(VIRTUAL);  ok
   // newf(uc);   ok
    
    

}
