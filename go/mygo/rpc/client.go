package main

import (
	"./pkg"
	"fmt"
	"net/rpc"
	//"net"
	"log"
	//"time"
	//"net/http"
)

type Args struct {
	A, B int
}

type Quotient struct {
	Quo, Rem int
}

type Arith int

func main(){
client, err := rpc.DialHTTP("tcp","localhost:1234")
if err != nil {
	log.Fatal("dialing:", err)
}
//Then it can make a remote call:

args := &pkg.Args{7,8}
var reply int
err = client.Call("Arith.Multiply", args, &reply)
if err != nil {
	log.Fatal("arith error:", err)
}
fmt.Printf("Arith: %d*%d=%d", args.A, args.B, reply)

}


