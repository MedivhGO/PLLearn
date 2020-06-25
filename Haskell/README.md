# Haskell 学习笔记

## Haskell简介

- 在纯粹函数式程序语言中的函数能做 的唯一事情就是利用引数计算结果,不会产生所谓的  副作用 一开始会觉得这限制很大,不过这也是他 的优点所在:若以同样的参数调用同一个函数两次,得到的结果一定是相同。 这被称作 “引用透明 (Referential Transparency)”
- Haskell 是惰性 (lazy) 的。也就是说若非特殊指明,函数在真正需要结 果以前不会被求值。
- Haskell 是静态类型 (statically typed) 的。当你编译程序时,编译器需要明确哪个是数字,哪个是字符串。这就意味着很大一部分错误都可以在编译 时被发现,若试图将一个数字和字符串相加,编译器就会报错。
- Haskell 拥有一套强大的类型系统,支持自动类型推导 (type inference)。这一来你就不 需要在每段源代码上都标明它的类型,像计算 a=5+4,你就不需另告诉编译 器 “ a 是一个数值”,它可以自己推导出来。
- Haskell 采纳了很多高阶程序语言的概念,因而它的源代码优雅且简练。 与同层次的命令式语言相比,Haskell 的源代码往往会更短,更短就意味着 更容易理解,bug 也就更少。

**在这份教学中我们会使用 目前最流行的版本:GHC**

从网上下载相应平台版本的Ghc包，解压后进入到解压的包中，
```shell
./configure
make install
```
完成安装
进入到命令行
执行ghci命令进入到交互式的界面中(control+d)退出
***
## 常见的运算子
"\*" 就是一个将两个数相乘的函数,就像三明治一样,用两个参数将它夹在中央,这被称作 **中缀函数**。而其他大多数不能与数夹在一起的函数则被称作**前缀函数**。绝大部分函数都是前缀函数。

第一个Haskell程序
```Haskell
succ 8 //返回8后面的数 9
```
在Haskell中是用空格来将函数与参数分隔的。至于调用多个参数的函数也很容易,min 和 max 接受两个可比较大小的参数,并返回较大或者较小的那个数。

**函数调用拥有最高的优先级**
Haskell 中的函数并没有顺序,所以先声明 doubleUs 还是先声明 doubleMe 都是同样的。
在这里有两点需要注意。首先就是我们没有大写conan的首字母,因为 首字母大写的函数是不允许的。（类型名大写）

- ++
- :
- !!


```Haskell
Prelude> 'A':"SMALL CAT"
"ASMALL CAT"
```
在使用 ++ 运算子处理长字符串时要格外小心 (对长 List 也是同样), Haskell 会遍历整个的 List(++ 符号左边的那个)。在处理较短的字符串时问 题还不大,但要是在一个 5000 万长度的 List 上追加元素,那可得执行好一 会儿了。所以说,用 : 运算子往一个 List 前端插入元素会是更好的选择。
## 常用的数据结构List

- 对于list中常用的函数
1. head 返回list中的第一个元素
2. tail 返回list中除去第一个元素之外的所有元素
3. last 返回最后一个元素
4. init 返回除去最后一个元素之外的所有元素
5. length 返回一个list的长度
6. null 判断一个list是否为空，空返回true 非空就返回false
7. reverse 将一个list转置
8. take [n] 返回一个list的前几个元素（若n超过list的长度则返回整个list）
9. drop 删除list的前几个元素（用法同上）
10. maximum 返回一个list中最大的那个元素
11. minimum 返回一个list中最小的那个元素
12. sum 返回一个list中的所有元素的和
13. product 返回一个list中所有元素的积
14. elem 判断一个元素是否包含于一个list，通常以中缀函数的形式调用它

- Range函数
写出元素为1-20的list可以使用range
```Haskell
[1..20]
[2,4..20]
[3,6..20]
```
无限长度的List
由于 Haskell 是惰性的,它不会对无限长度的 List 求值,否则会没完没 了的。它会等着,看你会从它那儿取多少。在这里它见你只要 24 个元素。
cycle函数接受一个list做参数，并返回一个无限的List
```Haskell
take 10 (cycle [1,2,3])
take 12 (cycle "LOL")
```
repeat 接受一个值做参数，
replicate 3 10
[10,10,10]
Range使用时尽量避免浮点数

### List comprehension

```Haskell
Prelude> [x*2|x <- [1..10],x*2 >= 12]
[12,14,16,18,20]
```
编写自己的length函数 length`
```Haskell
length` xs = sum[1|_ <- xs]
```

嵌套list的处理
```Haskell
*Main> let xxs = [[1,3,5,2,3,1,2,4,5],[1,2,3,4,5,6,7,8,9],[1,2,4,2,1,6,3,1,3,2,3]]
*Main> [[x|x <- xs,even x]|xs <-xxs]
[[2,2,4],[2,4,6,8],[2,4,2,6,2]]
*Main>
```

## Tuple元组

Tuple 中的项由括号括起,并由逗号隔开。

可以有单元素的list,但tuple不行。想想看,单元素的Tuple本身就 只有一个值,对我们又有啥意义?不靠谱。

fst 返回一个序对的首项
snd 返回序对的尾项
**这两个函数仅对序对有效，而不能应用于三元组，四元组，五元组之上**

zip
它可以用来生成一组序对Pair 的List。 它取两个List,然后将它们交叉配对,形成一组序对的list
当两个list长度不匹配时，较长的那个list会从中间断开


## Types and Typeclasses

之前我们有说过Haskell是Static Type,这表示在编译时期每个表达式 的类型都已经确定下来,这提高了源代码的安全性。

:t 命令后跟任何可用的表达式，即可得到该表达式的类型

```Haskell
:t 'a'
:t true
:t "HELLO!"
```

可以看出, :t 命令处理一个表达式的输出结果为表达式后跟::及其类型,::读作 它的类型为 。

### Type variables
```Haskell
ghci> :t head
head :: [a] -> a
```
想想我们在前面说过,凡是类型其首字母必大写, 所以它不会是个类型。
它是个类型变量，意味着a可以是任意的类型。这一点与其他语言中的泛型（generic）很相似，但在Haskell中要更为强大，他可以让我们轻而易举地写出类型无关的函数，使用到类型变量的函数称作“多态函数”，head函数的类型声明里标明了他可以取任意类型的List并返回其中的第一个元素。
在命名上,类型变量使用多个字符是合法的,不过约定俗成,通常都是 使用单个字符,如 a,b,c,d
### Typeclasses

```Haskell
Prelude> :t (==)
(==) :: Eq a => a -> a -> Bool
```
 => 符号，它左边的部分叫做类型约束
 相等函数取两个相同类型的值作为参数并返回一个布尔值，而这两个参数的类型同在Eq类之中（即类型约束）
 Eq这一Typeclass提供了判断相等性的界面，凡是可比较相等性的类型必属于 Eq class

 几个基本的Typeclass
 1. 包含可判断相等性的类型
 2. 包含可比较大小的类型
 3. compare函数取两个Ord类中的相同类型的值作参数,返回比较的结 果。这个结果是如下三种类型之一:GT,LT,EQ。
 4. Show的成员为可用字符串表示的类型。目前为止,除函数以外的所有 类型都是Show的成员。操作Show Typeclass,最常用的函数表示show。它 可以取任一Show的成员类型并将其转为字符串.
 5. Read与Show相反的TypeClass。read函数可以将一个字符串转为Read的某成员类型。
 6. Enum的成员都是连续的类型，也就是可枚举。Enum类存在的主要好处就在于我们可以在Rang中用到他的成员类型：每个值都有后继子和前置子，分别可以通过succ函数和pred函数得到。该Typeclass包含的类型有：（），Bool，Char，Ordering，Int，Integer，Float，Double
 7. Bounded的成员都有一个上限和下限
 如果其中的项都属于Bounded Typeclass,那么该Tuple也属于Bounded
 ```Hashkell
Prelude> maxBound ::(Bool,Int,Char)
(True,9223372036854775807,'\1114111')
 ```    
 8. Num是表示数字的Typeclass，它的成员类型都具有数字的特征，检查一个数字的类型
 类型只有亲近Show和Eq，才可以加入Num
 9. Integral同样是表示数字的Typeclass.Num包含所有的数字：实数和整数。而Integer仅包含整数，其中的成员类型有Int和Integer
 10. Floating仅包含浮点类型：Float和Double
 11. 有个函数在处理数字时会非常有用，它便是fromIntegral。其类型声明为：fromIntegral::(Num b,Integral a) => a-> b 从中我们可以看出，它取一个整数做参数并返回一个更加通用的数字，这在同时处理整数和浮点数时尤为有用。
 



