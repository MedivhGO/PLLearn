# C++中的类型转换
## 显示转换
### 命名的强制类型转换
1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast

```c++
 cast-name<type>(expression)
 //其中type是转换的目标类型，expression是要转换的值
 //castname是上表所列的4个转换类型名中的一种
```
#### static_cast
任何具有明确定义的类型转换，只要不包含底层const，都可以使用static_cast。

```c++
 int i,j;
 double slope = i/j;
 double slope = static_cast<double>(j)/i;//强制转换以便执行浮点除法。
 
```
当一个较大的算术类型转换成一个较小的算术类型，如果没有使用static_cast 就会显示警告，使用static_cast警告就消失了，因为编译器已经默认接受可能出现的精度损失。

static_cast对于编译器无法自动执行的类型转换也非常有用。

```c++
    void *p = &d; 
    double *dp = static_cast<double* >(p);
```

### const_cast
const_cast 只能改变运算对象的底层const

```c++
const char *pc;
char *p = const_cast<char*>(pc);
```
如果对象本身本事一个常量，使用强制类型转换获得写的权限是合法的行为，然而如果对象是一个常量，再使用const_cast执行写操作就会产生未定义的后果。
### reinterpret_cast
reinterpret_cast 通常为运算对象的位模式提供较低层次上的重新解释。

```c++
int *ip;
char *pc = reinterpret_cast<char *>(ip);
```
我们必须牢记pc所指的真实对象是一个int而非字符，如果把pc当成普通的的字符串指针使用就可能在运行时发生错误。

```c++
 string str(pc); //会发生错误。
```
当我们用一个int的地址初始化pc时，由于显式的声称这种转化合法，所以编译器不会发出任何警告或错误信息。

