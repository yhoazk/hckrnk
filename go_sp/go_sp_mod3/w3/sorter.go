package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

/*
Write a program to sort an array of integers. The program should partition the
array into 4 parts, each of which is sorted by a different goroutine. Each
partition should be of approximately equal size. Then the main goroutine should
merge the 4 sorted subarrays into one large sorted array.

The program should prompt the user to input a series of integers. Each
goroutine which sorts ¼ of the array should print the subarray that it will
sort. When sorting is complete, the main goroutine should print the entire
sorted list.
*/

func SliceSorter(section []int, result chan []int) {
	fmt.Printf("In fnc %v\n", section)
	sort.Ints(section)
	result <- section
}

func SliceMerger(left []int, rigth []int) []int {
	fmt.Printf("L: %v\n", left)
	fmt.Printf("R: %v\n", rigth)
	left_len, right_len := len(left), len(rigth)
	merged_sorterd := make([]int, left_len+right_len)
	sort_idx := 0
	l_ptr, r_ptr := 0, 0
	for l_ptr < left_len && r_ptr < right_len {
		if left[l_ptr] < rigth[r_ptr] {
			merged_sorterd[sort_idx] = left[l_ptr]
			l_ptr++
		} else {
			merged_sorterd[sort_idx] = rigth[r_ptr]
			r_ptr++
		}
		fmt.Println(merged_sorterd)
		sort_idx++
		fmt.Printf("Idx: %v lptr: %v rptr: %v\n", sort_idx, l_ptr, r_ptr)
	}
	// sort_idx = 0
	for l_ptr < left_len {
		fmt.Printf("LLL Idx: %v lptr: %v rptr: %v\n", sort_idx, l_ptr, r_ptr)
		merged_sorterd[sort_idx] = left[l_ptr]
		l_ptr++
		sort_idx++
	}
	for r_ptr < right_len {
		fmt.Printf("RRR Idx: %v lptr: %v rptr: %v\n", sort_idx, l_ptr, r_ptr)
		merged_sorterd[sort_idx] = rigth[r_ptr]
		r_ptr++
		sort_idx++
	}
	return merged_sorterd
}

func main() {
	fmt.Println("Type a single space separated list of integers to sort:")
	values := make([]int, 0)
	var pieces_sorted = make(chan []int, 4)

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		ints := strings.Split(scanner.Text(), " ")
		for _, v := range ints {
			v, _ := strconv.Atoi(v)
			values = append(values, v)
		}
	}

	min_size := len(values) / 4
	sizes := make([]int, 4)
	sub_sorted := make([][]int, 4)

	for idx, _ := range sizes {
		var inc int
		if idx < len(values)%4 {
			inc = 1
		}
		sizes[idx] = int(min_size) + inc
	}
	fmt.Printf("Len: %v\n", len(values))
	fmt.Println(sizes)

	start := 0
	for i := 0; i < 4; i++ {
		tmp := make([]int, sizes[i])
		copy(tmp, values[start:start+sizes[i]])
		go SliceSorter(tmp, pieces_sorted)
		start += sizes[i]
	}

	for idx, sli := range sub_sorted {
		sli = <-pieces_sorted
		sub_sorted[idx] = sli
		fmt.Printf("chan: %v\n", sli)
	}

	fmt.Println(values)
	fmt.Println(sub_sorted)

	sorted_result := SliceMerger(SliceMerger(sub_sorted[0], sub_sorted[1]), SliceMerger(sub_sorted[2], sub_sorted[3]))

	sort.Ints(values)
	for idx, v := range values {
		if v != sorted_result[idx] {
			fmt.Printf("Failure: Mismatch with reference sort\n\tRef[%v] = %v while Merge[%v] = %v", idx, v, idx, sorted_result[idx])
		}
	}

}

// 1 2 33 4 5 6 7 88
//
