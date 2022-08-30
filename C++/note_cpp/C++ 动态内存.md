# c++中的动态内存
## 内存模型
1. 静态内存：局部static对象，类static数据成员。（编译器创建和销毁）
2. 栈内存：定义在函数内的非static对象 （编译器创建和销毁）
3. 内存池： （自由空间）[free store] 称为heap （堆）  程序用堆来存储（动态分配）的对象。

## 动态内存与智能指针
new 和 delete 运算符

内存管理出现的问题
1. 内存泄漏
2. 空指针（指针悬空）

### 两种智能指针类(smart pointer)
1. shared_ptr   允许多个指针指向同一个对象
2. unique_ptr   独占所指向的对象   
3. weak_ptr     它是一种弱引用

> 以上三个类全都定义在 <memory> 头文件中

```c++

shared_ptr<int> ip; //默认的智能指针中保存着一个空指针。
shared_ptr<string> sp;
shared_ptr<list<int>> ilp; //指向链表的智能指针

```
### 智能指针上的操作

1. p
2. *p
3. p->mem
4. p.get()
5. swap(p,q)
6. p.swap(q)

#### shared_ptr 上独有的操作

make_shared<T> (args) 返回一个shared_ptr指针，指向 T 类型的对象。 args 为构造器的参数  

shared_ptr<T> p(q)

p = q //会递减p的引用计数，递增q的引用计数。若p的引用计数变为0，则将其管理的原内存释放。

p.unique() // 如果引用计数为1 返回true 否则返回false

p.use_count() //返回与p共享的智能指针数量。 
### make_shared 

**通常我们使用auto来保存make_shared的结果。**

shared_ptr 会自动销毁所管理的对象。

在最后一个shared_ptr 销毁前内存都不会释放。
所以要保证shared_ptr在无用之后不用在保留。

## 使用了动态生存期的资源类
程序使用动态内存出于以下三种原因之一
1. 程序不知道自己需要使用多少对象
2. 程序不知道所需对象的准确类型
3. 程序需要在多个对象间共享数据