# 智能指针的初始化

## 使用make_shared进行初始化

## shared_ptr 和 new 结合使用

```
shared_ptr<double> p1;
shared_ptr<int> p2(new int(42));

shared_ptr<int> p1 = new int(42);//错误，必须使用直接初始化形式
shared_ptr<int> p2 (new int(42)); //使用了直接初始化形式

```
**不能进行内置类型的指针到智能指针的转换**  所以11行的代码是错误的。

## 智能指针对象的操作

1. shared_ptr<T> p(q);
2. shared_ptr<T> p(u);// u是unique_ptr操作之后，u将被置空
3. shared_ptr<T> p(q,d);
4. shared_ptr<T> p(p2,d);
5. p.reset();  //若p是唯一指向其对象的shared_ptr,reset将会释放此对象。
6. p.reset(q);
7. p.reset(q,d);

## 不要混合使用普通指针和智能指针

## 也不要使用get初始化另一个智能指针或为智能指针赋值

智能指针类型定义了一个名为get的函数，它返回一个内置指针。
使用get返回的指针的代码不能delete此指针。

## 其他shared_ptr操作

``` 
p = new int(1024) //错误，不能将一个指针赋予shared_ptr
p.reset(new int(1024); // p指向一个新对象



```
reset会更新引用计数，如果需要的话，会释放p指向的对象，reset成员经常与unique一起使用，来控制多个shared_ptr共享的对象，在改变底层对象之前，我们检查自己是否是当前对象仅有的用户。如果不是，在改变之前要制作一份新的拷贝。