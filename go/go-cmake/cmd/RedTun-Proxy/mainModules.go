package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"os/signal"
	"redtun"
	"time"
)

const CONFIG_FILE_DEFAULT_NAME = "rd_config.yaml"

func parseCmdArgs(configUri *string) {

	dir, err := os.Getwd()
	if err != nil {
		dir = CONFIG_FILE_DEFAULT_NAME
	} else {
		dir += "/" + CONFIG_FILE_DEFAULT_NAME
	}

	flag.StringVar(configUri, "c", dir, "Config file path")

	flag.Parse()
}

func catchCmdSignals(redisTun *redtun.RT) {
	sigs := make(chan os.Signal, 1)
	signal.Notify(sigs, os.Interrupt)
	go func() {
		for sig := range sigs {
			// sig is a ^C, handle it
			switch sig {
			case os.Interrupt:
				err := redisTun.Neter.UnixServer.RmUnixFile()

				if err != nil {
					log.Println(err)
				}

				os.Exit(0)
			}
		}
	}()
}

func showBanner() {
	bannerData := `    ____           ________          
   / __ \___  ____/ /_  __/_  ______ 
  / /_/ / _ \/ __  / / / / / / / __ \
 / _, _/  __/ /_/ / / / / /_/ / / / /
/_/ |_|\___/\__,_/ /_/  \__,_/_/ /_/ 
                                     
      Redis Client Middleware
________ ________ ________ ________
`
	fmt.Println(bannerData)
	time.Sleep(time.Millisecond * 100)
}
