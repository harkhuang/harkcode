package main

import (
	"errors"
	"fmt"
	"net/http"
	"net/rpc"
)
//func () NAME (ARGS TYPE, REPLY TYPE) error
type Req struct{
	A,B int
}

type Math int


type Res int

type Quotient struct {
	Quo, Rem int
}

func (m *Math)Multiply(req *Req,reply *int) error{
	*reply = req.A * req.B
	return nil
}



func (m *Math) Divide(req *Req, quo *Quotient) error {
	if req.B == 0{
		return errors.New("divede by zero...")
	}
	quo.Quo = req.A
	quo.Rem = req.B
	return nil
}


func (m *Math)MyRpcSrv(req *Req,reply *int) error{
	*reply = req.A * req.B
	return nil
}

func (ret *Math) MyRpcSrv1(req *Req,  res *int) error {
	*res = req.A * req.B
	return nil
}
func main() {
	math := new(Math)
	rpc.Register(math)
	rpc.HandleHTTP()

	err := http.ListenAndServe(":1234", nil)
	if err != nil{
		fmt.Println(err.Error())
	}
}