// --- Day 4: The Ideal Stocking Stuffer ---

// Santa needs help mining some AdventCoins (very similar to bitcoins) to use as gifts for all the economically forward-thinking little girls and boys.

// To do this, he needs to find MD5 hashes which, in hexadecimal, start with at least five zeroes. The input to the MD5 hash is some secret key (your puzzle input, given below) followed by a number in decimal. To mine AdventCoins, you must find Santa the lowest positive number (no leading zeroes: 1, 2, 3, ...) that produces such a hash.

// For example:

//     If your secret key is abcdef, the answer is 609043, because the MD5 hash of abcdef609043 starts with five zeroes (000001dbbfa...), and it is the lowest such number to do so.
//     If your secret key is pqrstuv, the lowest number it combines with to make an MD5 hash starting with five zeroes is 1048970; that is, the MD5 hash of pqrstuv1048970 looks like 000006136ef....

// Your puzzle input is iwrupvqb
// sample prog: https://pkg.go.dev/crypto/md5
// package main

// import (
// 	"crypto/md5"
// 	"fmt"
// )

// func main() {
// 	data := []byte("iwrupvqb346386")
// 	fmt.Printf("%x", md5.Sum(data))
// }

package main

import (
	"crypto/md5"
	"fmt"
	"strconv"
)

// "crypto/md5"

func check(data []byte) bool {
	sample := []byte{0, 0, 15}
	for i, e := range sample {
		// fmt.Printf("%d == %d\n", e, data[i])
		if !(data[i] <= e) {
			return false
		}
	}
	return true
}

func main() {
	b := []byte{0, 0, 16}
	if check(b[:]) {
		fmt.Println("EQ")
	} else {
		fmt.Println("NEQ")
	}
	// var eq bool = true
	// data := []byte("abcdef609043")
	data := []byte("iwrupvqb346386") // Nope

	hash := md5.Sum(data)
	fmt.Println("test hash")
	fmt.Println(hash)
	if check(hash[:5]) {
		fmt.Println("ok")
	} else {
		fmt.Println("NOK")
	}

	fmt.Printf("Sample hash: %x\n", hash)
	fmt.Printf("Sample hash: %x\n", b)

	var inc int = 0
	data_puzzle := []byte("iwrupvqb")
	// extend with a string from an int
	for {
		c := strconv.Itoa(inc)
		buff := data_puzzle
		cc := []byte(c)
		buff = append(buff, cc[:]...)
		// fmt.Print(string(buff[:]))
		// fmt.Printf(": %x\n", hash)

		hash = md5.Sum(buff)
		if check(hash[:6]) {
			// fmt.Print(string(buff[:]))
			// fmt.Printf(": %x\n", hash)
			// if inc > 10 {
			break
		}
		inc++
	}
}
