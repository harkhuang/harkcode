package main

import (
	"fmt"
	"time"
)

func main() {
	//ch1 := 100
	ch1 := make(chan string,100)
	go pump(ch1)  // go 关键字表示执行协程 开始生产
	go suck(ch1)  // go 协程关键字    消费channel
	time.Sleep(1e9)
}

func pump(ch chan string) {
    for i := 0; ; i++ {

        ch <- string(i)
    }
}
func suck(ch chan string) {
    for int i := 0; ;i++{
		fmt.Println(<-ch)
		fmt.Println(i)
    }
}
 

