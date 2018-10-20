package main


import (
	"fmt"
)
func main() {
    var p *int = nil
	*p = 0
	


	var i1 = 5
    fmt.Printf("An integer: %d, its location in memory: %p\n", i1, &i1)
    var intP *int
    intP = &i1
    fmt.Printf("The value at memory location %p is %d\n", intP, *intP)

}
// in Windows: stops only with: <exit code="-1073741819" msg="process crashed"/>
// runtime error: invalid memory address or nil pointer dereference