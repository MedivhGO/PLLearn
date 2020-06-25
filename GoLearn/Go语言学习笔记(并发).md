# 并发的含义

并行是并发设计的理想执行模式

多线程或多进程是并行的基本条件,但单线程也可以使用协程做到并发.尽管协程在单个线程上通过主动切换来实现多任务并发,但他也有自己的优势.

协程上运行的多个任务本质上依旧是串行的,加上可控自主调度,所以并不需要做同步处理.

goroutine归纳为协程并不合适.运行时会创建多个线程来执行并发任务,且任务单元可被调度到其他线程并行执行.这更像是多线程和协程的综合体,能最大限度的提升执行效率,发挥多核处理能力.



## 创建并发任务


```
go println("hello, world!")

go func(s string) {
    println(s)
}("hello, world!")

```

与defer一样,goroutine也会因为"延迟执行"而立即计算并复制执行参数.

```Go

var c int

func counter() int {
    c++
    return c
}

func main() {
    a := 100

    go func(x,y int) {
        time.Sleep(time.Second)
        println("go:",x,y)
    }(a,counter())

    a+=100

    println("main: ",a,counter())

    time.Sleep(time.Second*3)
}



```

进程退出时不会等待并发任务结束,可用通道(channel)阻塞,然后发出退出信号.

```

	exit := make(chan struct{})//创建通道.因为仅是通知,数据并没有实际意义.

	go func() {
		time.Sleep(time.Second)

		println("goroutine done. ")

		close(exit)//关闭通道,发出信号.
	}()

	println("main...")
	<-exit //如通道关闭,立即解除阻塞

	println("main exit")



//运行结果:

//main...
//goroutine done.
//main exit

```


如果要等待多个任务结束,推荐使用sync.WaitGroup.通过设定计数器,让每个goroutine在退出前递减,直至归零时解除阻塞.

```
func main() {

	var wg sync.WaitGroup

	for i := 0; i < 10; i++ {
		wg.Add(1)

		go func(id int) {
			defer wg.Done()

			time.Sleep(time.Second)

			println("goroutine", id, "done. ")
		}(i)
	}

	println("main...")

	wg.Wait()

	println("main exit.")

}





//不会按顺序,但是当所有变量都执行完后就会结///束阻塞继续向后执行.


main...
goroutine 7 done.
goroutine 5 done.
goroutine 3 done.
goroutine 8 done.
goroutine 4 done.
goroutine 2 done.
goroutine 6 done.
goroutine 9 done.
goroutine 0 done.
goroutine 1 done.
main exit.

```

可以在多处使用Wait阻塞,他们都能接收到通知.


## GOMAXPROCS

运行时可能会创建很多线程,但任何时候仅有限的几个线程参与并发任务执行.该数量默认与处理器核数相等,可用runtime.GOMAXPROCS函数(或韩静变量)修改.