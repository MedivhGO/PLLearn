# new, operator new ,placement new


## new operator

1. 调用operator new 分配内存；
2. 嗲用构造函数生成类对象；
3. 返回相应的指针；

## operator new

1. 只分配所要求的空间，不调用相关对象的构造函数。当无法满足所要求分配的空间时，则
   - 如果有new_handler，则调用new_handler,否则
   - 如果没有要求不抛出异常(以nothrow参数表达)，则执行bad_alloc异常，否则
   - 返回0
2. 可以被重载；
3. 重载时，返回类型必须声明为void*
4. 重载时，第一个参数类型必须为表达要求分配空间的大小，类型size_t
5. 重载时，可以带其他参数。

## placement new

placement new 是重载operator new的一个标准，全局的版本，它不能够被自定义的版本代替（不像普通版本的operator new 和 operator delete能够被代替）。

```C++
void *operator new (size_t,void p) throw() {return p;}
```

在已有的内存空间上创建对象

```C++
class MyClass{};
char buf*  = new char[N*sizeof(MyClass) + sizeof(int)];
// char buf[N*sizeof(MyClass)+sizeof(int)]

MyClass *p = new (buf) MyClass //placement new
p->~MyClass() //析构对象，但是不释放空间。
    
delete p[] //堆上释放空间
```

placement new 的返回值是这个被构造对象的地址(比如括号中的传递参数)

STL中用到了这个技巧

uninitialized_copy() 函数，就是依次拷贝数据时，调用拷贝构造函数，而不会调用赋值函数。

拷贝很多数据的时候，如果要调用赋值函数，那么就得new一个出来。然后再复制，增加无用的开销。



