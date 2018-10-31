package main

import (
	"os"
	"fmt"
	"log"
	"net/rpc"
	
)

type Args struct{
	A,B int
}

type Quotient struct {
	Quo, Rem int
}


func main() {
	if len(os.Args ) !=  2{
		fmt.Println("Usage:",os.Args[0], "server");
		os.Exit(1);
	}
	serverAddr := os.Args[1];

	client,err:=rpc.DialHTTP("tcp",serverAddr + ":1234")
	if err != nil{
		log.Fatal("dialing:", err)
	}

	args:=Args{2,99}
	var reply int 
	err = client.Call("Math.Multiply", args, &reply)
	if err != nil{
		log.Fatal("Math error 1  ", err)
	}
	fmt.Println("Math  %d*%d=%d",args.A,args.B,reply)

	var quo Quotient
	err = client.Call("Math.Divide", args, &quo)
	if err != nil {
		log.Fatal("Math error2  ", err)
	}
	fmt.Println("Math: %d/%d=%d     remainder %d",args.A,args.B,quo.Quo,quo.Rem)
}