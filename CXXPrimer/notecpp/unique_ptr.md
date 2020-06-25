一个unique_ptr 拥有 它所指向的对象。
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