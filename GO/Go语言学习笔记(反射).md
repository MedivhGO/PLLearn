# 类型

反射让我们能在运行期探知对象的类型信息和内存结构,这从一定程度上弥补了静态语言在动态行为上的不足.同时,反射还是实现元编程的中重要手段.

**反射操作所需要的全部信息都来自接口变量,接口变量除存储自身类型外,还会保存实际对象的类型数据.

```
func TypeOf(i interface{}) Type
func Value(i interface{}) Value
```

这两个反射入口函数,会将任何传入的对象转换为接口类型.


在面对类型时,需要区分Type和Kind.前者表示真实类型(静态类型),后者表示其基础结构(底层类型)类别.

```Go

type X int

func main() {
    var a X = 100
    
    t := reflect.TypeOf(a)
    
    fmt.Println(t.Name(),t.Kind())
}


```

除通过实际对象获取类型外,也可以直接构造一些基础复合类型

```Go

func main() {
    a := reflect.ArrayOf(10,reflect.TypeOf(byte(0)))
    
    m := reflect.MapOf(reflect.TypeOf(""),reflect.TypeOf(0))
    
    fmt.Println(a,m)
}


```


方法Elem返回指针,数组,字典,切片,字典(值)或通道类型的基类.

```Go

func main() {
    fmt.Println(reflect.TypeOf(map[string]int{}).Elem())
    
    fmt.Println(reflect.TypeOf([]int32{}).Elem)
}



```

使用反射遍历结构体的字段.

只有在获取结构体指针的基类型后,才能遍历它的字段.

```
package main

import (
	"fmt"
	"reflect"
)

type user struct {
	name string
	age  int
}

type manager struct {
	user
	title string
}

func main() {

	var m manager
	t := reflect.TypeOf(&m)

	if t.Kind() == reflect.Ptr {
		t = t.Elem()
	}

	for i := 0; i < t.NumField(); i++ {
		f := t.Field(i)
		fmt.Println(f.Name, f.Type, f.Offset)

		if f.Anonymous {
			for x := 0; x < f.Type.NumField(); x++ {
				af := f.Type.Field(x)
				fmt.Println("   ", af.Name, af.Type)
			}
		}
	}
}


user main.user 0
    name string
    age int
title string 24

```


### 使用反射提取 struct tag

```Go

type user struct {
    name string `field: "name" type:"varchar(50)"`
    
    age int `field:"age" type:"int"`
    
}

func main() {
    var u user
    t := reflect.TypeOf(u)
    
    
    for i:=0; i < t.NumField(); i++ {
        f := t.Field(i)
        
        fmt.Printf("%s: %s %s\n",f.Name,f.Tag.Get("field"),f.Tag.Get("type"))
    }
}

//运行结果
name: name varchar(50)
age: age int

```

### 辅助判断方法都是运行期进行动态调用和赋值所必须的



```Go

type X int

func (X) String string {
    return ""
}

func main() {
    var a X
    
    t := reflect.TypeOf(a)
    
    st := reflect.TypePf((*fmt.Stringer)(nil)).Elem()
    
    fmt.Println(t.Implements(st))
    
    it := reflect.TypeOf(0)
    
    fmt.Println(t.ConvertibleTo(it))
    
    fmt.Println(t.AssignableTo(st),t.AssignableTo(it))
    
}

```


## 值


接口变量会复制对象,且是unaddressable的,所以想要修改目标对象,就必须使用指针.


```Go

package main

import (
	"fmt"
	"reflect"
)

func main() {
	a := 100

	va, vp := reflect.ValueOf(a), reflect.ValueOf(&a).Elem()

	fmt.Println(va.CanAddr(), va.CanSet())
	fmt.Println(vp.CanAddr(), vp.CanSet())

}


false false
true true
```


不能对非导出字段直接进行设置操作,无论是当前包还是外包

```Go

type User struct {
    Name string
    code int
}

func main() {
    p := new(User)
    
    v := reflect.ValueOf(p).Elem()
    
    name := v.FieldByName("Name")
    code := v.FieldByName("code")
    
    fmt.Printf("name: canaddr = &v, canset = %v\n",name.CanAddr(),name.CanSet())
    
    fmt.Printf("code: canaddr = &v, canset = %v\n",code.CanAddr(),code.CanSet())
    
    if name.CanSet() {
        name.SetString("Tom")
    }
    
    if code.CanSet() {
        *(*int)(unsafe.Pointer(code.UnsafeAddr())) = 100
    }
    
    fmt.Printf("%+v\n",*p)
}


运行结果

name: canaddr = &v, canset = true
%!(EXTRA bool=true)code: canaddr = &v, canset = true
%!(EXTRA bool=false){Name:Tom code:0}


因为成员code是不可导入成员,所以只能对其进行读操作,不能写.

```

