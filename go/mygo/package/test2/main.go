package main

import "fmt"
import "./bar1"   //此处引入的是包所在路径的名字

func main() {
	bar.Abc()
	fmt.Print("This is main\n")
}
