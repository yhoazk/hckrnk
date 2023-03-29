package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode/utf8"
)

/*
1. Write a program which reads information from a file
2. and represents it in a slice of structs.

3. Assume that there is a text file which contains a series of names.
4. Each line of the text file has a first name and a last name, in that order,
   separated by a single space on the line.
5. Your program will define a name struct which has two fields,
	5.1 fname for the first name,
	5.2 and lname for the last name.
6. Each field will be a string of size 20 (characters).

7. Your program should prompt the user for the name of the text file.
8. Your program will successively read each line of the text file
9. and create a struct which contains the first and last names found in the
   file.
10. Each struct created will be added to a slice,
11. and after all lines have been read from the file, your program will have
    a slice containing one struct for each line in the file. After reading all
	lines from the file, your program should iterate through your slice of
	structs and print the first and last names found in each struct.
*/

//5
type Name struct {
	//5.1
	fname string
	//5.2
	lname string
}

//6
const FIELD_LENGTH = 20

func NewName(first string, last string) Name {
	if utf8.RuneCountInString(first) > FIELD_LENGTH {
		first = string([]rune(first)[:FIELD_LENGTH])
	}
	if utf8.RuneCountInString(last) > FIELD_LENGTH {
		last = string([]rune(last)[:FIELD_LENGTH])
	}

	return Name{fname: first, lname: last}
}

func main() {
	fname := ""
	//7
	fmt.Println("Please give the file name:")
	fmt.Scan(&fname)

	fd, err := os.Open(fname)
	defer fd.Close()

	if err != nil {
		fmt.Println(err)
		return
	}
	//8
	scanner := bufio.NewScanner(fd)
	scanner.Split(bufio.ScanLines)

	names_slice := []Name{}

	for scanner.Scan() {
		names := strings.Split(strings.TrimSpace(scanner.Text()), " ")
		if len(names) > 2 {
			fmt.Printf("Error in format of name file %v\n has len %v\n", strings.Join(names, " "), (len(names)))
			return
		}
		//9
		this_line_name := NewName(names[0], names[1])
		//10
		names_slice = append(names_slice, this_line_name)
	}

	for idx, names := range names_slice {
		fmt.Printf("[%v]\tfname: %v\tlname: %v\n", idx, names.fname, names.lname)
	}

}
