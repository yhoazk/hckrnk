package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var input string

	fmt.Println("Enter a string:")
	input_buff := bufio.NewReader(os.Stdin)
	input, err := input_buff.ReadString('\n')
	if err != nil {
		fmt.Println(err)
		return
	}
	input = strings.TrimSpace(strings.ToLower(input))
	found := strings.HasPrefix(input, "i") && strings.Contains(input, "a") && strings.HasSuffix(input, "n")
	if found {
		fmt.Println("Found!")
	} else {
		fmt.Println("Not Found!")
	}
}
