## 条件编译

除在代码中用runtime.GOOS进行判断外,编译器本身就支持文件级别的条件编译.

1. 将平台和架构信息添加到主文件名结尾

例如 :

hello_darwin.go 

hello_linux.go

2. 使用build编译指令

与用文件名区分多版本类似,build编译指令告知编译器:当前源码文件只能用于指定环境.它一样可用来区分多版本,且可控制指令更加丰富和灵活.

例如

a.go
```
//+build windows
                     <--必须有空行

package main

func hello() {
    println("hello, windows.")
}
```

b.go
```
//+build liunx darwin

package main

func hello() {
    println("hello, unix.")
}
```

可添加多条build指令,表示多个and条件,在单一指令里,空格表示or条件,逗号表示and,叹号表示not


```Go

//+build linux darwin
//+build 386, !cgo

相当于:

(linux OR darwin) and (386 AND (NOT cgo))


```

3. 使用自定义tag指令

除预定义build指令外,也可通过命令行tags参数传递自定义指令

### 预处理

简单点说,就是用go generate命令扫描源码文件,找出所有"go:generate"注释,提取其中的命令并执行.


