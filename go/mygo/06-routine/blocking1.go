package main

import (
    "fmt"
)

func f1(in chan string) {
    fmt.Println(<-in)
}


// 协程死锁举例
// 由于协程是无缓冲的  
// 死锁在go中能报错的
func main() {
    // 在缓冲满载（缓冲被全部使用）之前，
    // 给一个带缓冲的通道发送数据是不会阻塞的，而从通道读取数据也不会阻塞，直到缓冲空了。
    out := make(chan string, 100)
    out <- "a"
    go f1(out)
}


//若使用通道的缓冲，
//你的程序会在“请求”激增的时候表现更好：更具弹性，
//专业术语叫：更具有伸缩性（scalable）。要在首要位置使用无缓冲通道来设计算法，
//只在不确定的情况下使用缓冲。