package main

import (
	"fmt"
)

var a = "G"


func main() {
	n()
	m()
	n()
	fmt.Println()
}

func n() {
	print(a)
}

func m() {
	a = "O"
	print(a)
}
