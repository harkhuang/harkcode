package main

import "fmt"
//import "os"
func main(){
	s1 := make([]int, 3)
	fmt.Println(s1)



	s2 := []int{1,2,3,4,5,6}
	fmt.Println(s2)

	s4:=s2[3:5]
	fmt.Println(s4)
	fmt.Println(s2[3:5])
	fmt.Println(s2[3:6])


	s4 = append(s2,1,2,3)
	fmt.Println(s4)

	 fmt.Println("len is " , len(s1))
}