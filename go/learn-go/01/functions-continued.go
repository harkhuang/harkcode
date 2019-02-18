package main

import "fmt"


//当连续两个或多个函数的已命名形参类型相同时，除最后一个类型以外，其它都可以省略。


func add(x, y int) int {
	return x + y
}

func main() {
	fmt.Println(add(42, 13))
}
