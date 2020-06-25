# 智能指针和异常
在资源分配后，释放前发生异常，则资源无法被释放。
## 智能指针和哑类
一个网络库的例子
```
struct destination //表示我们正在连接什么
struct connection //使用连接所需要的信息
connection connect(destination*); //打开连接
void disconnect(connection);//关闭给定连接
void f(destination &d) {

    //获得一个连接，记住使用完后要关闭
    connection c = connect(&d);
    //使用连接
    //如果我们在f退出前忘记调用disconnect，就无法关闭c了
}
```
可以自定义一个删除器。
```
void end_connection(connection* p) { disconnect(*p); }
```
### 使用智能指针的陷阱
智能指针可以提供对动态内存分配的内存安全而又方便的管理，但这建立在正确使用的前提下。唯乐正确使用智能指针，我们必须坚持一些基本规范：

1. 不使用相同的内置指针初始化(或reset)多个智能指针。
2. 不delete get() 返回的指针。
3. 不使用get()初始化或reset另一个智能指针。
4. 如果你使用get()返回的指针，记住当最后一个对应的智能指针销毁后，你的指针就变为无效了。
5. 如果你使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器。