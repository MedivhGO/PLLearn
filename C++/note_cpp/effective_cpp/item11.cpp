#include <iostream>
using namespace std;
#define MAX_COLORS 20
class Widget
{
public:
    Widget(int seed);
    ~Widget();
    Widget&operator=(const Widget& rhs);
    void ToString();
    Widget(const Widget& rhs);

private:
    int *colorPallete;
};
void Widget::ToString()
{
    int i = 0;
    for (i = 0; i < MAX_COLORS; ++i)
    {
        cout << "colorPallete[" << i << "]:" << colorPallete[i] << endl;
    }
}
Widget::Widget(int seed) : colorPallete(new int[MAX_COLORS])
{
    int i = 0;
    for (i = 0; i < MAX_COLORS; ++i)
    {
        colorPallete[i] = seed + i;
    }
}
Widget::Widget(const Widget &rhs) : colorPallete(new int[MAX_COLORS])
{
    std::copy(rhs.colorPallete,rhs.colorPallete+MAX_COLORS,colorPallete);
}
 Widget& Widget::operator=(const Widget &rhs)  //处理带指针的类赋值的常用方法
{
    Widget tmp(rhs);
    std::swap(colorPallete,tmp.colorPallete); // trick 使用交换来和局部变量来自动析构赋值运算符左侧值
    return *this;
}
Widget::~Widget()
{
    delete[] colorPallete;
}
