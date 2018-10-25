package main

import "fmt"



func fibonacci(c, quit chan int) {
	x, y := 0, 1
	for {
    // 通过io复用向通道写入x循环队列channle中
		select {
		case c <- x:
			x, y = y, x+y
		case <-quit:
			fmt.Println("quit")
			return
		}
	}
}

func main() {
	c := make(chan int)
	quit := make(chan int)
  
  // 通过闭包 匿名调用10个协程  消费 通道数据
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println(<-c)
		}
		quit <- 0
	}()
	fibonacci(c, quit)
}




//out put 
/*
0
1
1
2
3
5
8
13
21
34
quit

*/
