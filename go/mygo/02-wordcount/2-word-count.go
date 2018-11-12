package main

import (
	//	"strings"
	//	"io"
	//	"hash/fnv"
	//	"io/ioutil"
	"os"
	//	"encoding/json"
	"bufio"
	"fmt"
)

func main() {
	file, err := os.Open("1.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanWords)

	var words []string

	for scanner.Scan() {
		words = append(words, scanner.Text())
	}

	fmt.Println("word list:")
	for _, word := range words {
		fmt.Println(word)
	}

}
