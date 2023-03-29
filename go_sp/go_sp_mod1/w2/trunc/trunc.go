package main

import "fmt"

func main() {
	var inputFloat float64
	_, err := fmt.Scan(&inputFloat)

	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println(int64(inputFloat))
}
