# 一个unique_ptr 拥有 它所指向的对象
## unique_ptr对象的初始化
```
unique_ptr<double> p1;
unique_ptr<double> p2(new double(32));
```
由于一个unique_ptr拥有它指向的对象，因此unique_ptr不支持普通的拷贝或赋值操作：
```
unique_ptr<string> p1(new string("stegosaurus"));
unique_ptr<string> p2(p1); //error
unique_ptr<string> p3;
p3 = p2 // error unique_ptr 不支持赋值操作
```
我们不能拷贝或赋值unique_ptr，但我们可以通过调用release或reset
将指针的所有权从一个unique_ptr转移给另一个unique

```
unique_ptr<string> p2(p1.release());
unique_ptr<string> p3(new string("Trex"));
p2.reset(p3.release());
```

## 传递unique_ptr参数和返回unique_ptr

```
unique_ptr<int> clone(int p) {
    return unique_ptr<int>(new int(p));
}
unique_ptr<int> clone(int p) {
    unique_ptr<int> ret(new int(p));
    
    return ret;
}
```
因为编译器知道返回的对象将要被销毁，在此情况下，编译器将执行一种特殊的拷贝。

```
void f(destination &d) {
    connection c = connect(&d);//打开连接
    //当p被销魂时，连接将会关闭
    unique_ptr<connection,decltype(end_connection)*>
        p(&c,end_connection);
    //使用连接
    //当f退出时(即使是由于异常而退出),connection会被正确关闭
}
```

# weak_ptr是一种不控制所指向对象生存期的智能指针

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
