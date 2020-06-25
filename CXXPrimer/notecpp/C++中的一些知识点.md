# C++中的一些知识点
## 关于 void* 指针问题
void* 指针是一种特殊类型的指针，可用于存放任意对象的地址。
void* 指针能够进行的操作有限，可以进行赋值操作，比较，函数传参。
不能直接从操作void* 所指向的对象。
void* 指针可以被其他非指向const类型的指针赋值
const void* 指针可以被指向const类型的指针赋值

```c++
double obj = 3.14,*pd = &obj;

void *pv = &obj;
pv = pd; // pv 可以存放任何类型的指针。
```

## constexpr 和 常量表达式
### constexpr
常量表达式是指值不会改变并且在**编译**过程就能得到计算结果的表达式。
1. 字面值是属于常量表达式。
2. 用常量表达式初始化的const对象也是常量表达式

c++11新标准规定允许将变量声明为*constexpr*类型以便由编译器来验证变量的值是否是一个常量表达式。声明为constexpr的变量一定是一个常量，而且必须用常量表达式进行初始化。

```c++
constexpr int mf = 20;
constexpr int limit = mf + 1;
constexpr int sz = size(); // 只有当size()是一个constexpr函数时才是一条正确的声明语句。
```
### constexpr函数
constexpr函数是指能用于常量表达式的函数。定义constexpr函数需要注意的几点。
1. 函数的返回类型及所有形参都得是字面值类型。
2. 函数的返回语句中必须有且仅有一条return语句。
3. constexpr函数被隐式的定义为内联函数。
4. 执行初始化任务时，编译器把对constexpr函数的调用替换成其结果值。
5. constexpr函数返回的不一定是常量表达式。
6. 内联函数和constexpr函数常被定义在头文件中。
## const的分层问题
### 顶层const
用名词*顶层const*（top-level const）表示指针本身是个常量，而用名词*底层const*(low-level const)表示指针所指对象是一个常量。
更一般的，顶层const可以表示任意的对象是常量。
底层const则与指针和引用等复合类型的基本类型部分有关。
**指针类型既可以是顶层const又可以是底层const**

```c++
    int i = 0;
    int* const p1 = &i; //不能改变p1的值是一个顶层const
    const int ci = 42; //不能改变ci的值是一个顶层const
    const int *p2 = &ci； //可以改变p2的值是一个底层const
    const int *const p3 = p2； //靠右边的是顶层const，靠左边的是底层const
    const int &r = ci； //r 是底层const
```
底层const的限制不能忽视，当执行对象的拷贝操作时，拷入拷出的对象必须有相同的底层const资格。或者两个对象的数据类型必须能够转换，非常量可以转换成常量，反之则不行。

```c++
    int *p = p3; //p没有底层const的资格，不能进行。
    p2 = p3; //p2,p3均有底层const的资格
    p2 = &i; //正确，int* 能转换成const int*
    int &r = ci; //普通的int & 不能绑定在 int 常量上。
    const int &r2 = i; //const int & 可以绑定到一个普通int 上。
```

