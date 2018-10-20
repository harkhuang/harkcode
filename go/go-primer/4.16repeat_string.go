package main

import (
	"strconv"
	"fmt"
	"strings"
)


func main(){
	
//	var origStr string = "Hi there! "
//	var newStr string 

	var newStr string = strings.Repeat("Hi there!", 3)
	fmt.Println(newStr)

	// 字符串 转换大小写 
	var upperStr string = strings.ToUpper("hi~, jack~")
	fmt.Println(upperStr)
	fmt.Println(strings.ToLower(upperStr))
	// 去除前后字符串的空格
	fmt.Println(strings.TrimSpace("      hi~wo shi sha dan  "))
	
	
	
	// 分割字符串
	fmt.Println()



	// 此处写=不能通过编译   返回值需要一个空间存   这里通过引用的方式来返回
	fmt.Println()

	fmt.Println("===strings.split(str)=====")
	s1 := strings.Split("ni-hao-ya","-")
	fmt.Println(s1)
	//遍历一个slice
	for _,val := range s1{
		fmt.Printf("%s : ", val)
	}











	fmt.Println()

	fmt.Println("===strings.Fields(str)=====")
	s2 := strings.Fields("ni hao ma ,wo de peng you")
	fmt.Println(s2)
	for _,val := range s2{
		fmt.Printf("%s",val)
	}

	//strings.Slice("hi,ni,hao,ma", ",")


	fmt.Println()

	fmt.Println("===strings.Jion(str)=====")
	// 在每个字符串后面加上了个字符
	fmt.Println(strings.Join(s2, ";"))
	




	fmt.Println("===strconv.IntSize=====")

	fmt.Println("The sizde of ints is:", strconv.IntSize)

	var an int 

	an , _ =strconv.Atoi("666")
	fmt.Printf("atoi:%d\n",an)

	
	an = an + 1

	fmt.Printf("itoa is:%s \n",strconv.Itoa(an))
}

/*
hk-mac:go-primer hk$ go run 4.16repeat_string.go
Hi there!Hi there!Hi there!
*/