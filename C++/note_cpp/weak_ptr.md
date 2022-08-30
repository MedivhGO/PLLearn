weak_ptr是一种不控制所指向对象生存期的智能指针，
它指向由一个shared_ptr管理的对象。
将一个weak_ptr绑定到
一个shared_ptr不会改变
shared_ptr的引用计数。
一旦最后一个指向对象的shared_ptr被销魂，对象对会被释放。
即使有weak_ptr指向对象，
对象还是会被释放，因此，weak_ptr的名字抓住了这种智能指针“弱”共享对象的特点。

## weak_ptr的初始化
我们用一个shared_ptr来初始化它
```
auto p = make_shared<int>(42);
weak_ptr<int> wp(p);

```
由于对象可能不存在，我们不能使用weak_ptr直接访问对象，而必须调用lock.
此函数检查weak_ptr指向的对象是否仍存在。
如果存在，lock返回一个指向共享对象的shared_ptr，与任何其他shared_ptr，类似，只要此shared_ptr存在，它所指向的底层对象就会一直存在。


```
if (shared_ptr<int> np = wp.lock()
{
    //在if中，np与p共享对象
}

```

待续
