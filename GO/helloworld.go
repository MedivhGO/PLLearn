package main

import "fmt"

type Weekday int

const (
	Sunday Weekday = iota // 0
	Monday
	Tuesday
	Wednesday
	Thursday
	Friday
	Saturday
)
const (
	_   = 1 << (10 * iota)
	KiB // 1024
	MiB // 1048576
	GiB // 1073741824
	TiB // 1099511627776 (exceeds 1 << 32)
	PiB // 1125899906842624
	EiB // 1152921504606846976
	ZiB // 1180591620717411303424 (exceeds 1 << 64)
	YiB // 1208925819614629174706176
)

func main() {
	fmt.Println("Hello, World")

	for i, r := range "Hello, 世界" {
		fmt.Printf("%d\t%q\t%d\n", i, r, r)
	}

	fmt.Println(string(65))
	fmt.Println(string(123456)) // error unicode code point

	s := "你好"
	fmt.Printf("% x\n", s)
	r := []rune(s)
	fmt.Printf("%x\n", r)

	fmt.Println(Wednesday)
	fmt.Println(YiB / ZiB) // YiB不能直接输出，在进行计算后得到一个能够在go中表示的类型值，才可以输出。

	var qr [3]int = [3]int{1, 2, 3}
	var rr [3]int = [3]int{1, 2}
	fmt.Printf("%d, %d \n", qr[2], rr[2])
	oneHundred := [...]int{99: -1}
	fmt.Println(oneHundred[99])

	ex_map := make(map[bool]string)
	ex_map[true] = "abc"
	ex_map[false] = "bec"
	fmt.Println(ex_map[true])
	fmt.Println(ex_map[false])

	val, ok := ex_map[true]
	if !ok {
		fmt.Println("error")
	}
	fmt.Println(val)
}
