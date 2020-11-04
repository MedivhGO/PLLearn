package main

import (
	"sync"
	"time"
	"fmt"
	"runtime"
)

type pool chan []byte
func newPool(cap int) pool {
	return make(chan []byte,cap)
}

func (p pool) get() []byte {
	var v []byte

	select {
		case v = <- p:
		default:
			v = make([]byte,10)
	}
	return v
}

func (p pool) put(b []byte) {
	select {
	case p <-b:
		default:
	}
}

func main() {
	runtime.GOMAXPROCS(4)
	var wg sync.WaitGroup

	sem:=make(chan struct{},2)

	for i:=0;i<5;i++ {
		wg.Add(1)

		go func(id int ) {
			defer wg.Done()

			sem <-struct{}{}
			defer func() {<-sem}()

			time.Sleep(time.Second*2)
			fmt.Println(id,time.Now())
		}(i)
	}
	wg.Wait()
}