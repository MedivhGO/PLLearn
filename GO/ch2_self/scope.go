package main

import "os"

func main() {
	var s string = "tmp"
	if f, err := os.Open(s); err != nil {
		return
	} else {
		f.ReadByte()
		f.Close()
	}
}
