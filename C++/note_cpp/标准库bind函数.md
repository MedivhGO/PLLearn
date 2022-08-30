# 标准库bind函数
##标准库函数bind简介
将bind函数看做一个通用的函数适配器。

##适配器
函数适配器：适配器是标准库中的一种机制，能使某种事物的行为看起来像另外一种事物一样。

* stack适配器接受一个顺序容器（除array或forward_list外），并使其操作起来像一个stack一样。 

```c++
    stack<int> stk(deq);//从dep拷贝元素到stk
```
默认情况下，stack和queue是基于deque实现的，priority_queue是在vector之上实现的。我们可以在创建一个适配器时将一个命名的顺序容器作为第二个类型参数，来重载默认容器类型。

```c++
    //在vector上实现stack
   stack<string,vector<string>> stk_str;
```

对于一个给定的适配器，可以使用哪些容器是有限制的，所有适配器都要求容器具有**加和删除**的能力。

##bind函数的使用
调用bind的一般形式

```c++
    auto newCallable = bind(callable,arg_list);
    
```
其中，newCallable本身是一个可调用对象，arg_list是一个逗号分隔的参数列表，对应该给定的callable的参数， _即当我们调用newCallable时，newCallable会调用callable并传递给它arg_list_ .

## 绑定check_size的sz参数

```c++
    //check6是一个可调用的对象，接受一个string类型的参数
    //并用此string和值6来调用check_size
    auto check6 = bind(check_size,_1,6);
    此bind调用只有一个占位符，表示check6只接受单一参数。
    
    string s = “hello”;
    bool b1 = check6(s);
    
    //使用bind，我们可以将原来基于lambda的find_if调用
    
    auto wc = find_if(words.begin(),words.end(),
    [sz](const string &a));
    
    //替换为如下使用check_size的版本
    
    auto wc = find_if(words.begin(),words.end(),bind(check_size,_1,sz));
```
## 用bind重排参数顺序
下面是用bind重排参数顺序的一个例子，我们可以用bind颠倒isShroter的含义：

```c++
    //按单词长度由短至长排序
    sort(words.begin(),words.end(),isShorter);
    //按单词长度由长至短排序
    sort(words.begin(),words.end(),bind(isShorter,_2,_1));
```
##  绑定引用参数

```c++
    for_each(words.begin(),words.end(),
    bind(print, ref(os),_1,' '));
```
函数ref()返回一个对象，包含给定参数的引用，此对象是可以拷贝的，标准库中还有一个cref()函数，生成一个保存const引用的类，与bind一样，函数ref和cref也定义在头文件functional中。


