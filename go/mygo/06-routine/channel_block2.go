package main

import (
	"fmt"
	"time"
)

func main() {
	ch1 := make(chan int)
	go pump(ch1)  // go 关键字表示执行协程 开始生产
	go suck(ch1)  // go 协程关键字    消费channel
	time.Sleep(1e9)
}

func pump(ch chan int) {
    for i := 0; ; i++ {
        ch <- i
    }
}
func suck(ch chan int) {
    for {
        fmt.Println(<-ch)
    }
}
 

