/*
A maximum of 3 points will be given for the first test execution, if the program
correctly prints the sorted slice after entering three distinct integers.
**Points are awarded incrementally each time that an integer is added and it correctly prints the sorted slice.

A maximum of 2 points will be given for the second test execution, if the program
correctly prints the sorted slice after entering four distinct integers.
**Points are awarded if it correctly prints the sorted slice after adding the fourth integer.

Write a program which prompts the user to enter integers and stores the integers in a sorted slice.
The program should be written as a loop. Before entering the loop, the program should create an
empty integer slice of size (length) 3. During each pass through the loop, the program prompts
the user to enter an integer to be added to the slice. The program adds the integer to the slice,
sorts the slice, and prints the contents of the slice in sorted order.
The slice must grow in size to accommodate any number of integers which the user decides to enter.
The program should only quit (exiting the loop) when the user enters the character ‘X’
instead of an integer.

*/
//https://pandas-datareader.readthedocs.io/en/latest/remote_data.html
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func sort2(sli *[]int, n int) {
	swap_last_loop := false
	done := false

	for !done {
		for i := 0; i < n-1; i++ {
			if i >= len(*sli)-1 {
				break
			} else {
				val := (*sli)[i]
				if val < (*sli)[i+1] {
					(*sli)[i] = (*sli)[i+1]
					(*sli)[i+1] = val
					swap_last_loop = true
				}
			}
		}
		done = !swap_last_loop
		swap_last_loop = false
	}
}

func main() {
	sli := make([]int, 3)
	sli_idx := 0
	var input string
	fmt.Println("give numbers:")

	for {
		fmt.Scan(&input)
		input = strings.TrimSpace(input)

		if input == "X" {
			break
		}
		int_in, _ := strconv.Atoi(input)

		if sli_idx < len(sli) {
			sli[sli_idx] = int_in
		} else {
			sli = append(sli, int_in)
		}
		sli_idx += 1
		sort2(&sli, sli_idx)
		fmt.Println(sli)
	}
}
