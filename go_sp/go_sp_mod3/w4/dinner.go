package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

/*
Implement the dining philosopher’s problem with the following constraints/modifications.

1[x]. There should be 5 philosophers sharing chopsticks, with one chopstick between each
	adjacent pair of philosophers.
2[x]. Each philosopher should eat only 3 times (not in an infinite loop as we did in lecture)
3[]. The philosophers pick up the chopsticks in any order, not lowest-numbered first (which we did in lecture).
4[]. In order to eat, a philosopher must get permission from a host which executes in its own goroutine.
5[]. The host allows no more than 2 philosophers to eat concurrently.
6[x]. Each philosopher is numbered, 1 through 5.
7[x]. When a philosopher starts eating (after it has obtained necessary locks) it prints
   “starting to eat <number>” on a line by itself, where <number> is the number of the philosopher.
8[x]. When a philosopher finishes eating (before it has released its locks) it prints
	“finishing eating <number>” on a line by itself, where <number> is the number of the philosopher.
*/

const (
	NUM_PHILOSOPHERS = 5
	NUM_CHOPSTICKS   = 5
	NUM_TIMES_TO_EAT = 3
)

type Chopstick struct {
	mu    sync.Mutex
	taken bool
}

func (c *Chopstick) TakeChopstick() {
	c.mu.Lock()
	defer c.mu.Unlock()
	c.taken = true
}

type Philosopher struct {
	to_eat     int
	index      int
	chopsticks []bool
}

// iterate over the list of available chopsticks and returns
// one if available.
func (p *Philosopher) TryGetChopstick(chops *[]Chopstick) (int, bool) {
	idx := 0
	taken := false
	for i := 0; i < len(*chops); i++ {
		if !(*chops)[i].taken {
			fmt.Println("blockcck")
			(*chops)[i].mu.Lock()
			(*chops)[i].taken = true
			idx = i
			taken = true
			(*chops)[i].mu.Unlock()
		}
	}
	return idx, taken
}

func ReleaseChopstick(idx int) {
	fmt.Printf("Releasing chopstick %v\n", idx)
}

func (p *Philosopher) TryToEat(chops *[]Chopstick) {
	fmt.Printf("Phil %v tries to eat\n", p.index)
	if chop_idx, acquired0 := p.TryGetChopstick(chops); acquired0 {
		fmt.Printf("Phil %v got one chopstick\n", p.index)
		if chop_idx_2, aqcuired1 := p.TryGetChopstick(chops); aqcuired1 {
			// got two chops sticks, ask host for access
			fmt.Printf("Phil %v got second chopstick\n", p.index)
			// if p.AskHost() {
			p.StartEating()
			// host stops the philosopher?
			// time.Sleep(time.Millisecond * 2)  Works
			// time.Sleep(time.Millisecond * rand.Intn(50)) // Does not Work
			eating_for := time.Millisecond * time.Duration(rand.Intn(100))
			time.Sleep(eating_for)
			p.StopEating()
			// }
			ReleaseChopstick(chop_idx_2)
		}
		// I did not got two chopsticks, release the last chopstick
		ReleaseChopstick(chop_idx)
	}
}

// func (p *Philosopher) AskHost() bool {
// func (p *Philosopher) AskHost(host chan bool) {
// }

func (p *Philosopher) InformHostRelease(host chan bool) {
}

// func (p *Philosopher) StartEating(host chan bool) {
func (p *Philosopher) StartEating() {
	fmt.Printf("Philosopher %v starts eating\n", p.index)
}

// func (p *Philosopher) StopEating(host chan bool) {
func (p *Philosopher) StopEating() {
	fmt.Printf("Philosopher %v stops eating\n", p.index)
	p.to_eat--
}

func InitPhilosopers(p *Philosopher, idx int) {
	p.to_eat = NUM_TIMES_TO_EAT
	p.index = idx
	p.chopsticks = []bool{false, false}
}

// host has two seats which gives to any philisopher with
// two forks ready
// func host() {

// }

func main() {
	phi := make([]Philosopher, NUM_PHILOSOPHERS)
	chops := make([]Chopstick, NUM_CHOPSTICKS)
	for idx, _ := range phi {
		InitPhilosopers(&phi[idx], idx+1)
	}

	for i := 0; i < 50; i++ {
		for _, philosoper := range phi {
			fmt.Printf("Idx: %v to_eat: %v\n", philosoper.index, philosoper.to_eat)
			if philosoper.to_eat > 0 {
				philosoper.TryToEat(&chops)
			}
		}
	}
}
