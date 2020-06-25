# 数据


## 字符串

### 遍历字符串

1. byte 遍历
2. rune 遍历


```Go

func main() {

    s := "雨痕"


    for i:=0; i < len(s); i++ { //byte
       fmt.Printf("%d: [%c]\n",i,s[i])
    }

    for i,c := range s { // rune:返回数组索引号,以及Unicode字符
        fmt.Printf("%d: [%c]\n", i,c)
    }

}


0: [é]
1: [
2: [¨]
3: [ç]
4: []
5: []
0: [雨]
3: [痕]

```

字符串修改要先将其改变为可变类型([]rune或[]byte),待完成后再转换回来,但不管如何转换,都必须重新分配内存,并复制数据.



```Go

package main

import (
	"fmt"
	"reflect"
	"unsafe"
)

func pp(format string, ptr interface{}) {
	p := reflect.ValueOf(ptr).Pointer()

	h := (*uintptr)(unsafe.Pointer(p))

	fmt.Printf(format, *h)

}

func main() {

	s := "hello, world!"

	pp("s: %x\n", &s)

	bs := []byte(s)

	s2 := string(bs)

	pp("string to []byte, bs: %x\n", &bs)

	pp("[]byte to string, s2: %x\n", &s2)

	rs := []rune(s)
	s3 := string(rs)

	pp("string to []rune, rs: %x\n", &rs)
	pp("[]rune to string, s3: %x\n", &s3)

}

s: 10d2df5
string to []byte, bs: c000086030
[]byte to string, s2: c000086040
string to []rune, rs: c00008c040
[]rune to string, s3: c000086060


```

## 数组

定义数组时要数组的长度要是非负的整型常量表达式,长度是数组类型的组成部分,也就是说元素类型相同,但长度不同的数组不属于同一类型.

```Go

func main() {
    var d1 [3]int
    var d2 [2]int

    d1 = d2 //error
}
```

### 定义二维数组

```Go

package main

import (
	"fmt"
)

func main() {

	f := [...][2]int{
		{1, 2},
		{3, 4},
	}

	fmt.Println(f)
}

```

数组也支持" == "    " != " 操作 前提是数组中的元素支持该操作

```Go

func  main() {
    var a,b [2]int

    println(a == b)


    c := [2]int{1,2}

    d := [2]int{0,1}

    println(c != d)

    var e,f [2]map[string]int
}
```


### 指针

指针数组是指元素为指针类型的数组,数组指针是获取数组变量的地址

```Go

func main() {
    x,y := 10,20
    a := [...]*int(&x,&y) // 元素为指针的数组

    p := &a //存储数组地址的指针

    fmt.Printf("%T, %v\n",a,a)
    fmt.Printf("%T, %v\n",p,p)
}


输出的结果

[2]*int, [0xc000014080 0xc000014088]
*[2]*int, &[0xc000014080 0xc000014088]

```


### 复制

与C数组变量隐式作为指针使用不同,Go数组是值类型,赋值和传参操作都会复制整个数组数据

```Go

func test(x [2]int) {
    fmt.Printf("x: %p, %v\n",&x,x)
}

func main() {
    a := [2]int{10,20}

    var b [2]int

    b = a

    fmt.Printf("a: %p, %v\n",&a,a)
    fmt.Printf("b: %p, %v\n",&b,b)

    test(a)
}


输出结果

a: 0xc00008a010, [10 20]
b: 0xc00008a020, [10 20]
x: 0xc00008a060, [10 20]

```

由输出结果表明,在赋值和传参的过程中,都是创建了一个新的数组来存储这些值.


可以使用指针或切片,以此来避免数据复制

```Go

func test(x *[2]int) { //传入的是指针
    fmt.Printf("x:  %p, %v\n",x,*x)
    x[1] += 100
}

func main() {
    a := [2]int{10,20}
    test(&a)

    fmt.Printf("a: %p, %v\n",&a,a)
}

```

### 切片

切片(slice)本身并非动态数组或数组指针.它内部通过指针引用底层数组,设定相关的属性将数据读写操作限定在指定区域内.

可基于数组或者数组指针创建切片,以开始和结束索引位置确定所引用的数组片段.不支持反向索引,实际范围是一个右半开区间.

**切片本身是个只读对象,其工作机制类似数组指针的一种包装**

```Go

type slice struct {
    array unsafe.Pointer
    len int
}


```
### append

append向切片尾部添加数据,返回新的切片对象


```Go


func main() {

	s := make([]int, 0, 5)

	s1 := append(s, 10)

	s2 := append(s1, 20, 30)

	fmt.Println(s, len(s), cap(s))

	fmt.Println(s1, len(s1), cap(s1))

	fmt.Println(s2, len(s2), cap(s2))


[] 0 5
[10] 1 5
[10 20 30] 3 5

}



```

### copy

在两个切片对象间复制数据,允许指向同一底层数组,允许目标区间重叠,最终所复制长度以较短的切片长度为准
```Go


func main() {

	s := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

	s1 := s[5:8] //5 6 7

	n := copy(s[4:], s1)

	fmt.Println(n, s)

	s2 := make([]int, 6)

	n = copy(s2, s)

	fmt.Println(n, s2)

}

copy(dst,src)

3 [0 1 2 3 5 6 7 7 8 9]
6 [0 1 2 3 5 6]






```



### 字典

定义

```Go
func main() {
	m := make(map[string]int)
	m["a"] = 1
	m["b"] = 2

	m2 := map[int]struct {
		x int
	}{
		1: {x: 100},
		2: {x: 200},
	}

	fmt.Println(m, m2)
}

结果 : map[a:1 b:2] map[1:{100} 2:{200}]

```

***


```Go
func main() {
	m := map[string]int{
		"a": 1,
		"b": 2,
	}

	m["a"] = 10
	m["c"] = 30

	if v, ok := m["d"]; ok {
		println(v)
	}

	delete(m, "d")
}




```

访问不存在的键值,默认返回零值,不会引发错误.

#### 对键值进行迭代

**对字典中的键值进行迭代,每次返回的键值次序都不相同**

```Go

func main() {
    m := make(map[string]int)

    for i:=0; i < 8; i++ {
        m[string('a'+i)] = i
    }

    for i:=0 ; i < 4; i++ {
        for k,v := range m {
            print(k,":",v," ")
        }

        println()
    }
}


f:5 g:6 h:7 a:0 b:1 c:2 d:3 e:4
f:5 g:6 h:7 a:0 b:1 c:2 d:3 e:4
f:5 g:6 h:7 a:0 b:1 c:2 d:3 e:4
d:3 e:4 f:5 g:6 h:7 a:0 b:1 c:2

```

函数len返回当前键值对数量,cap不接受字典类型.

因为内存访问安全和哈希算法等缘故,字典被设计成"not addressable",故不能**直接**修改value成员(结构或数组)

```
func main() {
    type user struct {
        name string
        age byt
    }

    m := map[int] user {
        1:{"Tom",19}
    }

    m[1].age += 1 //
}


```

正确做法是返回整个value,待修改后再设置字典的键值,或直接用指针类型

```Go

type user struct {
    name string
    age byte
}

func main() {

    m := map[int]user {
        1: {"Tom",19},
        }

    u := m[1] //先得到这个值
    u.age += 1 //修改
    m[1] = u // 重新赋值


    m2 := map[int]*user {
        1: &user{"Jack",20},
    }

    m2[1].age++  //相当于m[key] = m[key]+1
}

```

不能对nil字典进行写操作,但却能读

```

func main() {
    var m map[string]int
    println(m["a"]) //返回零值
    m["a"] = 1 //error 不能对此赋值
}


内容为空的字典与nil是不同的

func main() {

    var ml map[string]int // nil字典
    m2 := map[string]int{} //同make操作空字典


    println(m1 == nil, m2 == nil)

}

true false

```

在迭代期间删除或新增键值是安全的

```
func main() {
	m := make(map[int]int)

	for i := 0; i < 10; i++ {
		m[i] = i + 10
	}

	for k := range m {
		if k == 5 {
			m[100] = 100
		}
		delete(m, k)
		fmt.Println(k, m)
	}

}

1 map[0:10 2:12 3:13 4:14 5:15 6:16 7:17 8:18 9:19]
5 map[0:10 2:12 3:13 4:14 6:16 7:17 8:18 9:19 100:100]
6 map[0:10 2:12 3:13 4:14 7:17 8:18 9:19 100:100]
7 map[0:10 2:12 3:13 4:14 8:18 9:19 100:100]
8 map[0:10 2:12 3:13 4:14 9:19 100:100]
9 map[0:10 2:12 3:13 4:14 100:100]
0 map[2:12 3:13 4:14 100:100]
2 map[3:13 4:14 100:100]
3 map[4:14 100:100]
4 map[100:100]


```





## 结构

定义结构格式

type 结构名 struct


### 空结构

如代码所示

```Go

func main() {
	var a struct{}
	var b [100]struct{}

	println(unsafe.Sizeof(a), unsafe.Sizeof(b))

}

//输出为
0 0
```

尽管没有分配数组内存,但依然可以操作元素,对应切片len,cap属性也正常.

```Go

func main() {
    var d [100]struct{}

    s := d[:]

    d[1] = struct{}{}
    s[2] = struct{}{}

    fmt.Println(s[3],len(s),cap(s))
}


```

实际上,这类"长度"为零的对象通常都指向runtime.zerobase变量


```Go

func main() {
    a:=[10]struct{}{}
    b:=a[:]
    c:=[0]int{}


    fmt.Printf("%p, %p, %p\n",&a[0],&b[0],&c)
}

//运行结果  0x1194a78, 0x1194a78, 0x1194a78

```

匿名字段,是指没有名字,仅有类型的字段,也被称作嵌入字段或嵌入类型.

从编译器的角度看,这只是隐式地以类型名作为字段的名字.可直接引用匿名字段的成员,但初始化时必须当做独立字段.



```
type data struct {
	*int
	string
} //两个匿名字段,都是类型名

func main() {
	x := 100
	d := data{
		int:    &x, //当使用指针做匿名字段时其初始化名称为其类型名,所以不能将基础类型和其指针类型同时嵌入.
		string: "abc",
	}

	fmt.Printf("%#v\n", d)
}



```


如果匿名字段成员被外层同名字段遮蔽,那么必须使用显示字段名.

```
type file struct {
	name string
}

type data struct {
	file
	name string
}

func main() {

	d := data{
		name: "data",
		file: file{"file"},
	}

	d.name = "data2"
	d.file.name = "file2" //使用显式字段名访问 data.file.name

	fmt.Println(d.name, d.file.name)

}




data2 file2
```



## 字段标签

字段标签(tag)并不是注释,而是用来对字段进行描述的元数据.尽管它不属于数据成员,但确实类型的组成部分.

在运行期,可用反射获取标签信息.它常用作格式校验,数据库关系映射等



```
type user struct {
	name string `昵称`
	sex  byte   `性别`
}

func main() {

	u := user{"Tom", 1}
	v := reflect.ValueOf(u)
	t := v.Type()

	for i, n := 0, t.NumField(); i < n; i++ {
		fmt.Println("%s: %v\n", t.Field(i).Tag, v.Field(i))
	}

}
```

使用reflect.ValueOf()来获得对象反射.