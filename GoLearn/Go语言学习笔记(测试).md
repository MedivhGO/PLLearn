## testing

工具链和标准库自带单元测试框架

* 测试代码必须放在当前包以"_test.go"结尾的文件中
* 测试函数以Test为名称前缀
* 测试命令(go test)忽略以"_"或"."开头的测试文件
* 正常编译操作(go build/install)会忽略测试文件

```Go

package main

import ("
    testing
")

func add(x,y int) int {
    return x + y
}

func TestAdd(t *testing.T) {
    if add(1,2) != 3 {
        t.FailNow()
    }
}

=== RUN   TestAdd
--- PASS: TestAdd (0.00s)
PASS
ok      _/Users/allen/Desktop/golangue  0.732s

```



### table driven

单元测试代码一样要写得简介优雅,要做到这点并不容易.好在多数时候,我们可以用一种类似数据表的模式来批量输入条件并依次对比结果

```Go

func TestAdd2(t *testing.T) {

	var tests = []struct {
		x      int
		y      int
		expect int
	}{
		{1, 1, 2},
		{2, 2, 4},
		{3, 2, 6},
	}

	for _, tt := range tests {
		actual := add(tt.x, tt.y)
		if actual != tt.expect {
			t.Errorf("add(%d, %d) : expect %d,actual %d", tt.x, tt.y, tt.expect, actual)
		}
	}
}

```

这种方式将测试数据和测试逻辑分离,更便于维护.另外,使用Error是为了让整个表全部完成测试,以便知道具体是哪组条件出现问题.

### test main

某些时候,须为测试用例提供初始化和清理操作,但testing并没有setup/teardown机制.

解决方法是自定义一个名为TestMain函数,go test命令会改为执行该函数,而不再是具体的测试用例

```Go

func TestMain(m *testing.M) {
    code := m.Run()

    os.Exit(code)
}


```

### example

例代码最大的用途不是测试,而是导入到GoDoc等工具生成的帮助文档中.它通过比对输出(stdout)结果和内部output注释是否一致来判断是否成功.



## 性能测试

性能测试函数以Benchmark为名称前缀,同样保存在"*_test.go"文件里

通过在 go test -bench .

命令后添加不同的参数,进行时间,内存,cpu等方面的测试.

- 使用benchtime设定最小测试时间.
- benchmem测定内存的单次执行时的分配量和操作次数.



### 性能监控

引发性能问题的原因不外乎执行时间过长,内存占用过多,以及意外阻塞.通过捕获或监控相关执行状态数据,,就可以定位引发问题的原因,从而有针对性的改进算法.

有两种捕获方式

1. 在测试时输出并保存相关数据,进行初期评估.
2. 在运行阶段通过web接口获得实时数据,分析一段时间内的健康状况.
3. 还可以使用自定义计数器(expvar)提供更多与逻辑相关的参考数据.






