package main

import (
    "fmt"
    "math/rand"
)

func main(){
	rand.Seed(41)  // random seed + enviroment + time = rand intiger 
	fmt.Println("My favorite numbe is :", rand.Intn(10))
}