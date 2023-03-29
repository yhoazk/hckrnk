package main

import (
	"fmt"
	"time"
)

/* In this demo there are several go routines which are started
   without synchronization. The shared resource is the stdout
   output buffer, since there is no control over who access it
   the image should be different each time this program is run
   and different between each row.
*/

func printer(c string) {
	fmt.Printf("%v", c)
}
func main() {
	for j := 0; j < 5; j++ {
		for i := 0; i < 5; i++ {
			go printer("▒")
			go printer("█")
		}
		time.Sleep(time.Millisecond * 5)
		fmt.Printf("\n")
	}
}
