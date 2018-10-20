package main

import (
	"fmt"
	"strings"
)


func main(){
	var str string = "Hello ,how is it going, hugo?"
	var manyG = "gggggggg"
	
	fmt.Printf("Number of H's in %s is :", str)
	fmt.Printf("%d\n", strings.Count(str, "H"))

	fmt.Printf("Number of double g's in %s is :", manyG)
	fmt.Printf("%d\n", strings.Count(manyG, "gg"))


}
