#include <iostream>
#include <string>
#include <map>
using namespace  std;
int main()
{
    if(word_count.erase(removal_word))
        cout << "ok" << removal_word << "removed\n";
    else
        cout << "oops" << removal_word << "not found!\n";

    //对于不重复的容器删除成功erase()方法返回1，删除失败erase方法返回0

    //对于重复的容器 删除成功 返回删除的元素个数

    //迭代器当做参数时返回的是删除元素的后一个迭代器，若指向尾元素则返回end
}