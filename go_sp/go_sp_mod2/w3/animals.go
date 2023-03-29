package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

/*
Test the program by running it and testing it by issuing three requests.
Each request should involve a different animal (cow, bird, snake) and a
different property of the animal (eat, move, speak). Give 2 points for each
request for which the program provides the correct response.

Examine the code. If the code contains a type called Animal, which is a struct
containing three fields, all of which are strings, then give another 2 points.
If the program contains three methods called Eat(), Move(), and Speak(), and
all of their receiver types are Animal, give another 2 points.
---
Write a program which allows the user to get information about a predefined
set of animals. Three animals are predefined, cow, bird, and snake.
Each animal can eat, move, and speak. The user can issue a request to find
out one of three things about an animal:

1) the food that it eats,
2) its method of locomotion, and
3) the sound it makes when it speaks.

The following table contains the three animals and their associated data which
should be hard-coded into your program.

|Animal | Food eaten  | Locomotion method | Spoken sound |
| ===== | =========== | ================= | ============ |
|cow    |  grass      |  walk             | moo          |
|bird   |  worms      |  fly              | peep         |
|snake  |  mice       |  slither          | hsss         |

Your program should present the user with a prompt, “>”, to indicate that the
user can type a request.

Your program accepts one request at a time from the user, prints out the answer
to the request, and prints out a new prompt. Your program should continue in
this loop forever. Every request from the user must be a single line containing
2 strings. The first string is the name of an animal, either “cow”, “bird”, or
“snake”. The second string is the name of the information requested about the
animal, either “eat”, “move”, or “speak”.
Your program should process each request by printing out the requested data.

You will need a data structure to hold the information about each animal.
Make a type called Animal which is a struct containing three fields:
- food,
- locomotion, and
- noise, all of which are strings.

Make three methods called Eat(), Move(), and Speak().
The receiver type of all of your methods should be your Animal type.
The Eat() method should print the animal’s food, the Move() method should print
 the animal’s locomotion, and the Speak() method should print the animal’s
 spoken sound. Your program should call the appropriate method when the user
 makes a request.
*/

type Animal struct {
	food, locomotion, noise string
}

func (a *Animal) Eat() {
	fmt.Println(a.food)
}
func (a *Animal) Move() {
	fmt.Println(a.locomotion)
}
func (a *Animal) Speak() {
	fmt.Println(a.noise)
}

func main() {
	done := false
	input_buff := bufio.NewReader(os.Stdin)
	animalMap := map[string]*Animal{
		"cow":   &Animal{"grass", "walk", "moo"},
		"bird":  &Animal{"worms", "fly", "peep"},
		"snake": &Animal{"mice", "slither", "hsss"},
	}
	actionMap := map[string]func(*Animal){
		"eat":   (*Animal).Eat,
		"move":  (*Animal).Move,
		"speak": (*Animal).Speak,
	}
	for !done {
		fmt.Print(">")
		input, err := input_buff.ReadString('\n')
		if err != nil {
			fmt.Println(err)
			return
		}
		cmds := strings.Split(input, " ")
		if len(cmds) > 2 {
			fmt.Println("Malformed expression")
			return
		}

		cmds[0] = strings.TrimSpace(cmds[0])
		cmds[1] = strings.TrimSpace(cmds[1])

		animal, animalExists := animalMap[cmds[0]]
		if !animalExists {
			fmt.Println("No such animal")
			continue
		}
		action, actionExists := actionMap[cmds[1]]
		if !actionExists {
			fmt.Println("No such action")
			continue
		}
		action(animal)
	}
}
