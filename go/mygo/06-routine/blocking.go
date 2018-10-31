package main

import (
    "fmt"
)

func f1(in chan int) {
    fmt.Println(<-in)
}


// 协程死锁举例
// 由于协程是无缓冲的  
// 死锁在go中能报错的
func main() {
    out := make(chan int)
    out <- 2
    go f1(out)
}