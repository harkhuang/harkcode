package main

import (
	"fmt"
)

var a = "G"

func n() {
	print(a)
}

func m() {
	a = "O"
	print(a)
}

func main() {
	n()
	m()
	n()
	fmt.Println()
}

