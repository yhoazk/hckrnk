package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

/*
Write a program which prompts the user to first enter a name, and then enter an address.
Your program should create a map and add the name and address to the map using the keys
“name” and “address”, respectively. Your program should use Marshal() to create a JSON
object from the map, and then your program should print the JSON object.

There is no specification about when to finish the program
*/

func main() {
	address_map := make(map[string]string)
	// var name, address string
	in_buffer := bufio.NewReader(os.Stdin)

	fmt.Println("Enter a name:")
	name, err := in_buffer.ReadString('\n')
	if err != nil {
		fmt.Println(err)
		return
	}
	name = strings.TrimSpace(name)

	fmt.Println("Enter an address:")
	address, err := in_buffer.ReadString('\n')
	if err != nil {
		fmt.Println(err)
	}

	address = strings.TrimSpace(address)
	address_map["name"] = name
	address_map["address"] = address

	address_map_byte, err := json.MarshalIndent(address_map, "", "\t")
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(string(address_map_byte))

}
