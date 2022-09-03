# C++ 中直接管理内存

## 使用new动态分配和初始化对象
```
int *pi = new int(1024);
string *ps = new string(10,'9');
vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
```
也可以对动态分配的对象进行值初始化，只需要类型名后面跟一对()

```
string *p1 = new string();
string *p2 = new string;
//因为string类类型自己定义了默认构造函数，所以p1 与 p2 的值是相同的

int *pi1 = new int // *pi1的值是不定的
int pi = new int() //使用值初始化，所以 *pi2为0
```
总之，对于动态分配的对象进行初始化是一个好主意。

如果我们提供了一个括号包围的初始化器，就可以使用auto从此初始化器来推断我们想要分配的对象的类型。 当括号中仅有单一初始化器时，才可以使用auto

```
auto p1 = new auto(obj);
auto p2 = new auto{a,b,c,d,e} //因为有多个初始化器，所以错误。
```

## 动态分配的const对象

用new分配const对象是合法的：
```
const int *pci = new const int(1024);
const string *pcs = new const string

```

## 内存耗尽

当自由空间被耗尽时，new表达式就会失败，如果new不能分配所要求的内存空间，他就会抛出一个 bad_alloc 的异常
```
int *p1 = new int
int *p2 = new (nothrow) int //如果失败，new返回一个空指针。
//我们称这种形式的new 为定位new(placement new)
//bad_alloc 和 nothrow 都定义在头文件new 中
```
## 使用delete释放内存

delete 所操作的指针必须是由 new所分配，或者是空指针。
释放一个非new开辟的区域或者相同的指针释放多次，其行为都是未定义的。

## 动态对象的生存周期知道被释放时为止

由内置指针(而不是智能指针)管理的动态内存在被显式释放前一直都会存在。


## 动态内存的管理非常容易出错。

1. 忘记delete内存。忘记释放动态内存会导致人们常说的 内存泄漏 问题，因为这种内存永远不可能被归还给自由空间了。查找内存泄漏错误是非常困难的，因为通常应用程序运行很长时间后，真正耗尽内存时，才能检测到这种错误。
2. 使用已经释放掉的对象。通过在释放内存后将指针置为空，有时可以检测出这种错误。
3.同一块内存释放两次，当有两个指针指向相同的动态分配对象时，可能发生这种错误。如果对其中一个指针进行了delete操作，对象的内存就被归还给自由空间了。如果我们随后又delete第二个指针，自由空间就可能被破坏。

**坚持只使用智能指针，就可以避免所有这些问题，对于一块内存，只有在没有任何智能指针指向它的情况下，智能指针才会自动释放它。**

### 练习

```
// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void read1(vector<int> *p) {
    int c;
    cin>>c;
    p->push_back(c);
    return ;
}
void output1(vector<int> *p) {
    cout << p->back();
    return ;
}
int main()
{
  vector<int> *p = new vector<int>();
  read1(p);
  output1(p);

  delete p;
  return 0;
  
}

```
改用shared_ptr
```
// Example program
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void read1(shared_ptr<vector<int>> p) {
    int c;
    cin>>c;
    p->push_back(c);//
    return;
}

void output1(shared_ptr<vector<int>> p) {
    cout << p->back();
    return;
}

int main()
{
  shared_ptr<vector<int>> p = make_shared<vector<int>>();
  read1(p);
  output1(p);
  return 0;
}

```