# 接口

接口代表一种调用契约,是多个方法声明的集合.

从内部实现莱卡接口自身也是一种结构类型,只是编译器会对其做出很多限制

```Go

type iface struct {
    tab *itab
    data unsafe.Pointer
}
```

* 不能有字段
* 不能定义自己的方法
* 只能声明方法,不能实现
* 可嵌入其他接口类型

接口通常以er结尾作为名称,方法名是声明组成的一部分,但参数名可不同或省略.


```Go

type tester interface {
	test()
	string() string
}

type data struct{}

func (*data) test() {}

func (data) string() string { return "" }

func main() {

	var d data
	//不存在基础类型到指着类型的转换
	//var t tester = d // data只实现了string方法没有实现 test方法

	//会把指针类型转换到基础类型
	var t tester = &d //实现了test方法

	t.test()

	println(t.string())

}


//编译器根据方法集来判断是否实现了接口,显然在上例中只有*data才符合tester的要求.
```

如果接口没有任何方法声明,那么就是一个空接口(interface{}),它的用途类似面向对象里的根类型Object,可被赋值为任何类型的对象.


接口变量默认值是nil,如果实现接口的类型支持,可以做相等运算.

```

func main() {

	var t1, t2 interface{}

	println(t1 == nil, t1 == t2)

	t1, t2 = 100, 100

	println(t1 == t2)

	t1, t2 = map[string]int{}, map[string]int{}

	println(t1 == t2)

}



//true true
//true
//panic: runtime error: comparing //uncomparable type map[string]int
```

### 匿名接口

支持匿名接口类型,可直接用于变量定义,或作为结构字段类型


```Go

type data struct{}

func (data) string() string {
	return "" //定义data类型的方法
}

type node struct {
	data interface { //匿名接口
		string() string
	}
}

func main() {

	var t interface { //定义接口变量
		string() string
	} = data{}

	n := node{ //初始化接口变量
		data: t,
	}

	println(n.data.string())
}




```


### 执行机制


接口使用一个名为itab的结构存储运行期所需要的相关类型信息.


```Go

type iface struct {
	tab  *itab  //类型信息
	data unsafe.Pointer //实际对象指针
}

type itab struct {
	inter *interfacetype //接口类型
	_type *_type //实际对象地址
	fun   [1]uintptr //实际对象方法
}

type Ner interface {
	a()
	b(int)
	c(string) string
}

type N int

func (N) a()               {}
func (*N) b(int)           {}
func (*N) c(string) string { return "" }

func main() {

	var n N
	var t Ner = &n

	t.a()
}


```


### 类型转换

```Go

package main

import "fmt"

type data int

func (d data) String() string {
	return fmt.Sprintf("data: %d", d)
}

func main() {
	var d data = 15

	var x interface{} = d

	if n, ok := x.(fmt.Stringer); ok {
		fmt.Println(n) //15
	}

	if d2, ok := x.(data); ok {
		fmt.Println(d2) //15
	}

	e := x.(error)
	fmt.Println(e)

}

```
