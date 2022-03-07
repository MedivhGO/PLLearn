# 方法

可以像访问匿名字段成员那样调用其方法,由编译器负责查找.

```Go

type data struct {
    sync.Mutex
    buf [1024]byte
}


func main() {
    d := data{}

    d.Lock()

    defer d.unlock()
}


```

方法也会有同名遮蔽问题.但是利用这种特性,可实现类似覆盖(override)操作.


```Go

type N int

type user struct {
}

type manager struct {
	user
}

func (user) toString() string {
	return "user"
}

func (m manager) toString() string {
	return m.user.toString() + "; manager"
}

func main() {

	var m manager

	println(m.toString())  //m的toString方法覆盖掉了user的toString方法
	println(m.user.toString())
}

输出
user; manager
user
```

### 方法集

类型有一个与之相关的方法集,这决定了它是否实现某个接口.

使用反射(reflect)测试这些规则

```
package main

import (
	"fmt"
	"reflect"
)

type S struct{}

type T struct {
	S
}

func (S) SVal()  {}
func (*S) SPtr() {}
func (T) TVal()  {}
func (*T) TPtr() {}

func methodSet(a interface{}) {

	t := reflect.TypeOf(a)
	for i, n := 0, t.NumMethod(); i < n; i++ {
		m := t.Method(i)
		fmt.Println(m.Name, m.Type)
	}
}

func main() {

	var t T

	methodSet(t)
	println("------")
	methodSet(&t)
}




```


### 表达式

方法和函数一样,除直接调用外,还可以赋值给变量,或作为参数传递.依照具体引用方式的不同,可以分为expression和value两种状态.

#### expression value

通过类型引用的method expression 会被还原为普通函数样式, receiver是第一个参数,调用时须显式传参.至于类型, 可以是T或*T,只要目标方法存在于类型方法集中即可.

#### method value


基于实例或指针引用的method value,参数签名不会改变,仍旧按正常方式调用.
将方法赋值给变量

会立即计算并复制该方法执行所需的receiver对象,与其绑定.

以便在稍后执行时,能隐式传入receiver参数

```Go

func (n N) test() {
	fmt.Printf("test.n: %p, %v\n", &n, n)
}

func main() {

	var n N = 100

	p := &n

	n++
	f1 := n.test

	n++

	f2 := p.test

	n++

	fmt.Printf("main.n: %p, %v\n", p, n)

	f1()
	f2()

}

main.n: 0xc000090008, 103
test.n: 0xc000090020, 101
test.n: 0xc000090030, 102
```

