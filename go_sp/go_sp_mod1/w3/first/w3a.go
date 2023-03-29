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

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// simple bubble sort
func sort(sli []int) {
	done := false
	swap_last_loop := false
	for !done {
		for idx, val := range sli {
			if idx == len(sli)-1 {
				continue
			} else {
				if val > sli[idx+1] {
					// swap
					sli[idx] = sli[idx+1]
					sli[idx+1] = val
					swap_last_loop = true
				}
			}
		}
		done = !swap_last_loop
		swap_last_loop = false
	}
}

func main() {
	var input string

	fmt.Println("Give integers to sort:")

	input_buff := bufio.NewReader(os.Stdin)
	input, err := input_buff.ReadString('\n')

	if err != nil {
		return
	}
	input_arr := strings.Split(strings.TrimSpace(input), " ")

	input_int_arr := make([]int, len(input_arr))
	sum := 0
	for i, n := range input_arr {
		val, err := strconv.Atoi(n)
		input_int_arr[i] = val
		if err != nil {
			fmt.Println(err)
		}
		sum += val

	}

	fmt.Println(input_int_arr)
	sort(input_int_arr)
	fmt.Println(input_int_arr)
}
