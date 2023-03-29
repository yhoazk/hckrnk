package main

import (
	"fmt"
	"log"
)

/*
Test the program by running it twice and
testing it with a different sequence of integers each time. The first test
sequence of integers should be all positive numbers and the second test should
have at least one negative number. Give 3 points if the program works correctly
for one test sequence, and give 3 more points if the program works correctly
for the second test sequence.

Examine the code. If the code contains a function
called BubbleSort() which takes a slice of integers as an argument, then
give another 2 points.If the code
contains a function called Swap() function which takes two arguments, a slice of
integers and an index value i, then give another 2 points.
---
The program should prompt the user to type in a sequence of up to 10 integers. The program
should print the integers out on one line, in sorted order, from least to
greatest. Use your favorite search tool to find a description of how the bubble
sort algorithm works.

As part of this program, you should write a function called BubbleSort() which takes
a slice of integers as an argument and returns nothing.
The BubbleSort() function should modify the slice so that the elements are in sorted
order.

A recurring operation in the bubble sort algorithm is the Swap operation which swaps
the position of two adjacent elements in the slice.
You should write a Swap() function which performs this operation. Your Swap()
function should take two arguments, a slice of integers and an index value i which
indicates a position in the slice. The Swap() function should return nothing, but it should swap
the contents of the slice in position i with the contents in position i+1.

Submit your Go program source code.

*/
func Swap(values []int, index int) {
	if index >= len(values)-1 {
		log.Fatal("Index out of bounds")
		// fmt.Println("----")
		return
	}
	tmp := values[index]
	values[index] = values[index+1]
	values[index+1] = tmp
}

func BubbleSort(vals []int) {

	done := false
	this_loop_swap := false
	for !done {
		for idx, val := range vals {
			if idx == len(vals)-1 {
				break
			}
			if val > vals[idx+1] {
				Swap(vals, idx)
				this_loop_swap = true
			}
		}
		done = !this_loop_swap
		this_loop_swap = false
	}
}

func main() {
	// enter a sequence of 10 integers
	values := make([]int, 10)

	for idx, _ := range values {
		fmt.Printf("Type integer %v/%v: ", idx+1, len(values))
		fmt.Scan(&values[idx])
	}
	BubbleSort(values)
	fmt.Printf("\nSorted list:\n")
	for _, v := range values {
		fmt.Printf("%v ", v)
	}
	fmt.Println("")
}
