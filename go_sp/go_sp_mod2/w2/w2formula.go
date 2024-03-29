package main

import (
	"fmt"
	"math"
)

/*
Review criteria

This assignment is worth a total of 10 points.

Test the program by running it twice and testing it with two different sets of
values for acceleration, initial velocity, initial displacement, and time.
Give 3 points if the program works correctly for one set of values, and give 3
more points if the program works correctly for the other set of values.

Examine the code. If the code contains a function called GenDisplaceFn() which
takes three float64 arguments, acceleration a, initial velocity vo, and initial
displacement so and returns a function, then give another 2 points. If the
function returned by GenDisplaceFn() is used to compute the time, give another
2 points.

---

Let us assume the following formula for displacement s as a function of time t,
acceleration a, initial velocity vo, and initial displacement so.

s = ½ a t^2 + vot + so

Write a program which first prompts the user to enter values for acceleration,
initial velocity, and initial displacement.

Then the program should prompt the user to enter a value for time and the
program should compute the displacement after the entered time.

You will need to define and use a function called GenDisplaceFn() which takes
three float64 arguments, acceleration a, initial velocity vo, and initial
displacement so.
GenDisplaceFn() should return a function which computes displacement as a
function of time, assuming the given values acceleration, initial velocity, and
initial displacement.
The function returned by GenDisplaceFn() should take one float64 argument t,
representing time, and return one float64 argument which is the displacement
travelled after time t.

For example, let’s say that I want to assume the following values for
acceleration, initial velocity, and initial displacement:
 a = 10, vo = 2, so = 1.
I can use the following statement to call GenDisplaceFn() to generate a function
fn which will compute displacement as a function of time.

fn := GenDisplaceFn(10, 2, 1)

Then I can use the following statement to print the displacement after 3
seconds.

fmt.Println(fn(3))

And I can use the following statement to print
the displacement after 5 seconds.

fmt.Println(fn(5))

*/

func GenDisplaceFn(a, vo, so float64) func(float64) float64 {

	return func(t float64) float64 {
		return 0.5*a*math.Pow(t, 2) + vo*t + so
	}

}

func main() {
	var a, vo, so, time float64
	fmt.Println("Enter value for acceleration (a):")
	fmt.Scan(&a)
	fmt.Println("Enter value for initial velocity (vo):")
	fmt.Scan(&vo)
	fmt.Println("Enter value for initial displacement (so):")
	fmt.Scan(&so)
	D_fn := GenDisplaceFn(a, vo, so)

	fmt.Println("Enter value for time (t):")
	fmt.Scan(&time)

	fmt.Println(D_fn(time))

}
