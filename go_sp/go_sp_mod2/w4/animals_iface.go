package main

/*

This assignment is worth 10 points.

Test the program by running it and issuing three newanimal commands followed by
three query commands. Each new animal should involve a different animal type
(cow, bird, snake), each with a different name. Each query should involve a
different animal and a different property of the animal (eat, move, speak).
Give 2 points for each query for which the program provides the correct
response.

Examine the code. If the code contains an interface type called Animal, which is
a struct containing three fields, all of which are strings, then give another 2
points. If the program contains three types – Cow, Bird, and Snake – which all
satisfy the Animal interface, give another 2 points.
---
Write a program which allows the user to create a set of animals and to get info
rmation about those animals. Each animal has a name and can be either a cow, bir
d, or snake. With each command, the user can either create a new animal of one o
f the three types, or the user can request information about an animal that he/s
he has already created. Each animal has a unique name, defined by the user. Note
that the user can define animals of a chosen type, but the types of animals are
restricted to either cow, bird, or snake. The following table contains the thre
e types of animals and their associated data.


| Animal   | Food Eaten   | Locomotion method | Spoken sound |
| -------- | -----------  | ----------------  | ------------ |
| cow      | grass        |  walk             |  moo         |
| bird     | worms        |  fly              |  peep        |
| snake    | mice         |  slither          |  hsss        |


Your program should present the user with a prompt, “>”, to indicate that the us
er can type a request. Your program should accept one command at a time from the
 user, print out a response, and print out a new prompt on a new line. Your prog
ram should continue in this loop forever. Every command from the user must be ei
ther a “newanimal” command or a “query” command
.

Each “newanimal” command must be a single line containing three strings. The fir
st string is “newanimal”. The second string is an arbitrary string which will be
the name of the new animal. The third string is the type of the new animal, eit
her “cow”, “bird”, or “snake”.  Your program should process each newanimal comma
nd by creating the new animal and printing “Created it!” on the screen.

Each “query” command must be a single line containing 3 strings. The first strin
g is “query”. The second string is the name of the animal. The third string is t
he name of the information requested about the animal, either “eat”, “move”, or
“speak”. Your program should process each query command by printing out the
requested data.

Define an interface type called Animal which describes the methods of an animal.
Specifically, the Animal interface should contain the methods Eat(), Move(), and
Speak(), which take no arguments and return no values. The Eat() method should
print the animal’s food, the Move() method should print the animal’s locomotion,
and the Speak() method should print the animal’s spoken sound. Define three
types Cow, Bird, and Snake. For each of these three types, define methods Eat(),
Move(), and Speak() so that the types Cow, Bird, and Snake all satisfy the Animal
interface. When the user creates an animal, create an object of the appropriate
type. Your program should call the appropriate method when the user issues a
query command.

*/

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strings"
)

const (
	CMD_NEWANIMAL = "newanimal"
	CMD_QUERY     = "query"
	TYPE_COW      = "cow"
	TYPE_BIRD     = "bird"
	TYPE_SNAKE    = "snake"
	ACTION_EAT    = "eat"
	ACTION_MOVE   = "move"
	ACTION_SPEAK  = "speak"
)

// type Animal struct {
// food, locomotion, sound string
// }

type Animal interface {
	Eat()
	Move()
	Speak()
}

type Cow struct{}

func (c *Cow) Eat() {
	fmt.Println("grass")
}
func (c *Cow) Move() {
	fmt.Println("walk")
}
func (c *Cow) Speak() {
	fmt.Println("moo")
}

type Bird struct{}

func (c *Bird) Eat() {
	fmt.Println("worms")
}
func (c *Bird) Move() {
	fmt.Println("fly")
}
func (c *Bird) Speak() {
	fmt.Println("peep")
}

type Snake struct{}

func (c *Snake) Eat() {
	fmt.Println("mice")
}
func (c *Snake) Move() {
	fmt.Println("slither")
}
func (c *Snake) Speak() {
	fmt.Println("hsss")
}

type AnimalEntry struct {
	name string
	Animal
}

func GetAnimalByName(name string, animals *[]AnimalEntry) (Animal, error) {
	for _, animal := range *animals {
		fmt.Println(animal.name)
		if name == animal.name {
			return animal, nil
		}
	}
	return nil, errors.New("Animal name not found")
}

func ExecuteActionAnimal(action string, animal *Animal) {
	switch action {
	case ACTION_EAT:
		(*animal).Eat()
	case ACTION_MOVE:
		(*animal).Move()
	case ACTION_SPEAK:
		(*animal).Speak()
	default:
		fmt.Println("Undefined action: %v\n", action)
		os.Exit(2)
	}
}

func AnimalFactory(class string) Animal {
	switch class {
	default:
	case TYPE_COW:
		return &Cow{}
	case TYPE_BIRD:
		return &Bird{}
	case TYPE_SNAKE:
		return &Snake{}
	}
	return nil
}

func main() {
	animals_db := map[string]Animal{}
	done := false
	input_buffer := bufio.NewReader(os.Stdin)
	for !done {
		fmt.Print(">")
		input, err := input_buffer.ReadString('\n')
		if err != nil {
			fmt.Println(err)
			return
		}
		input_tokens := strings.Split(input, " ")
		if len(input_tokens) != 3 {
			fmt.Printf("Incorrect number of arguments, 3 are expected, received %v\n", len(input_tokens))
			continue
		}

		command := strings.TrimSpace(input_tokens[0])
		animal_name := strings.TrimSpace(input_tokens[1])
		switch command {
		case CMD_NEWANIMAL:
			animal_type := strings.TrimSpace(input_tokens[2])
			if _, ok := animals_db[animal_name]; !ok {
				animals_db[animal_name] = AnimalFactory(animal_type)
			} else {
				fmt.Printf("An animal with name %v alredy exists\nIt will be preserved\n", animal_name)
			}
		case CMD_QUERY:
			animal_action := strings.TrimSpace(input_tokens[2])
			animal, animal_exists := animals_db[animal_name]
			if !animal_exists {
				fmt.Printf("No animal with name %v\n", animal_name)
				continue
			}
			ExecuteActionAnimal(animal_action, &animal)
		default:
			fmt.Printf("Unkown command %v\n", command)
			continue
		}
	}
}
