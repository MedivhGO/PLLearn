# C++中的lambda表达式
## lambda表达式简介
一个lambda表达式表示一个可调用的代码单元，我们可以将其理解为一个未命名的内联函数。
lambda具有一个返回类型，一个参数列表，一个函数体。
lambda函数可以定义在函数内部。一个lambda表达式具有如下形式

```c++
[capture list](parameter list) -> return type {function body}


```
其中的返回类型是**尾置返回**。
_尾置返回是另一种指明函数返回值得方式，尾置返回在函数的参数表之后使用 -> 类型名 来明确函数的返回值。_

capture list 是一个lambda所在函数中定义的局部变量列表（通常为空），return type，parameter list 和 function body 与任何普通函数一样。
我们可以**忽略参数列表和返回类型**，但必须永远_包含_**捕获列表和函数体** 。

```c++
auto f = []{return 42;};
```
## 向lambda传递参数
1.lambda不能有默认参数。

编写一个与isShorter函数完成相同功能的lambda。

```c++
[](const string &a ,const string &b) {
     return a.size() < b.size();
}
```

## 使用捕获列表
我们希望这个表达式可以将输入序列中的每一个String的长度与biggies函数中的sz参数的值进行比较。虽然一个lambda可以出现在一个函数中，使用其局部变量，但它只能使用那些明确指明的变量。捕获列表指引lambda再起内部包含访问局部变量所需的信息。

```c++
[sz](const string &a ) {
     return a.size() >= sz;
}
```
## 调用find_if
```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int sz = 3;
  vector<string> svec{"abc","aavdasdas","dasdasdd","dasdasd"};
  auto wc = find_if(svec.begin(),svec.end(),[sz](const string &a){return a.size() >= sz; } );
  
  cout << *wc << endl;

}
```
## for_each算法
打印words中长度大于等于sz的元素。for_each算法接受一个可调用对象，并对输入序列中的每个元素调用此对象。

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int sz = 3;
  vector<string> svec{"a","abc","aavdasdas","dasdasdd","dasdasd"};
  auto wc = find_if(svec.begin(),svec.end(),[sz](const string &a){return a.size() >= sz;});
  
  for_each(wc,svec.end(),[](const string &s){cout << s << " ";});
  cout << endl;

}```

## lambda捕获和返回
当定义一个lambda时，编译器生成一个与lambda对应的新的类类型。当向一个函数传递一个lambda时，同时定义了一个新类型和该类型的一个对象，传递的参数就是该类类型的未命名对象。

### 值捕获
```c++
    void fcn2()
    {
        size_t v1 = 42;
        
        auto f = [v1] {return v1;}; 
        
        v1 = 0;
        auto j = f();
    }
```
被捕获的变量的值是在lambda创建时拷贝的，而不是调用时拷贝的。
### 引用捕获
```c++
    void fcn2()
    {
        size_t v1 = 42;
        
        auto f2 = [&v1] {return v1;}; 
        
        v1 = 0;
        auto j = f2();
    }
```
被捕获的变量的值是在lambda创建时拷贝的，而不是调用时拷贝的。
*一般情况下我们应该尽量减少捕获的数据量，来避免潜在的捕获导致的问题，而且如果可能的话，应该避免捕获指针或引用。*
### 隐式捕获
为了指示编译器推断捕获列表，应在捕获列表中写一个 & 或 = 告诉编译器采用捕获方式。

* = 表示值引用。
* & 表示引用

如果我们希望对一部分变量采用值捕获，对其他变量采用引用捕获，可以混合使用隐式捕获和值捕获。

_当我们混合使用隐式捕获和显示捕获时，捕获列表中的第一个元素必须是一个&或=，次符号指定了默认捕获方式为引用或值_
### 可变lambda
如果我们希望能改变一个被捕获的变量的值，就必须在参数列表首加上关键字mutable。因此，可变lambda能省略参数列表。

```c++
    void func3()
    {
        size_t v1 = 42;
        
        auto f = [v1]() mutable{return ++v1;};
        
        v1 = 0;
        auto j =f();
    }
```
### 指定lambda返回类型
将一个序列中的所有负数转换成其绝对值。
transform算法接受三个迭代器，和一个可调用对象。
前2个迭代器表示输入序列，第三个迭代器表示目的位置。算法对输入序列中的每个元素调用可调用的对象，并将结果写到目的位置。

在本中我们给transform传递一个lambda，返回其参数的绝对值。

lambda体是单一个return语句，返回一个条件表达式的结果。我们无须指定返回类型。如果使用if语句，就会产生两个分支，两个return语句，编译器无法推断出返回值类型，就会给lambda指定一个void的返回类型。这时候我们的目的就不能达到。所以要明确的指出lambda的返回值。

下面是解决该问题的代码

```c++
    transform(vi.begin(),vi.end(),vi.begin(),
    [](int) -> int {if (i>0) return i; else return -i;} 
    )
```


