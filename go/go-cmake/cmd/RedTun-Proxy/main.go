package main

import (
	"log"
	//	_ "net/http/pprof"
	"redtun"
)

func main() {

	/*
			go func() {
				log.Println(http.ListenAndServe("localhost:6060", nil))
			}()
	*/
	showBanner()

	log.SetFlags(log.Lshortfile | log.LstdFlags)
	/*
	* Parse cmd Args
	* get config file uri
	*/
	var configFileUri string

	parseCmdArgs(&configFileUri)

	/*
	* Init New RedTun Item
	* init confer from Yaml file
	* init unix neter
	*/
	redisTun, err := redtun.GetNewRedTun(configFileUri)

	if err != nil {
		log.Fatalln(err)
	}

	/*
	* Create local UNIX listener
	* create unix listen items by Group opts
	*/

	//catch cmd Signal : os.Interrupt
	catchCmdSignals(&redisTun)

	//start api-handle server
	go redisTun.StartApiServer()

	/*
	* Start redis-server-handle listen
	*/
	neter := redisTun.Neter
	err = redisTun.Neter.UnixServer.StartServer(neter.RequestHandle, neter.AcceptHandle, neter.ClosedHandle)

	if err != nil {
		log.Fatalln(err)
	}

}
