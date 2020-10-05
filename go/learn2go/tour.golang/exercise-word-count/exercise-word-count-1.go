package main

import (
	"fmt"
	"math"
// 	"os"
	//"bufio"
)
func Uint8FromInt(n int) (uint8, error) {
    if 0 <= n && n <= math.MaxUint8 { // conversion is safe
        return uint8(n), nil
    }
    return 0, fmt.Errorf("%d is out of the uint8 range", n)
}
func main() {
	//var  ln = 1.123123123123123112312312312123123123123123123123123123123123123123123123123123123132
	//fmt.Println(ln + 324)



	Uint8FromInt(12)
	return 
}
