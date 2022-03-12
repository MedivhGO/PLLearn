package main

import "fmt"

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
}
