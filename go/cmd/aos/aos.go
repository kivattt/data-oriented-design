package main

import (
	"fmt"
	"strconv"
	"time"
)

type Thing struct {
	a string
	b string
	c string
	d []int
	e []int
	f int
}

func getThings() []Thing {
	intSlice := make([]int, 800)
	for i := range intSlice {
		intSlice[i] = 69
	}

	var thing Thing
	thing.a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj"
	thing.b = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj"
	thing.c = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj"

	thing.d = make([]int, 800)
	copy(thing.d, intSlice)
	thing.e = make([]int, 800)
	copy(thing.e, intSlice)
	thing.f = 69

	nThings := 300000
	things := make([]Thing, nThings)
	for i := range things {
		//things[i] = thing
		things[i].a = thing.a
		things[i].b = thing.b
		things[i].c = thing.c

		things[i].d = make([]int, 800)
		copy(things[i].d, thing.d)

		things[i].e = make([]int, 800)
		copy(things[i].e, thing.e)

		things[i].f = thing.f
	}

	return things
}

func main() {
	//defer profile.Start().Stop()

	things := getThings()

	start := time.Now()
	var sum uint64
	for _, thing := range things {
		for _, e := range thing.a {
			sum += uint64(e)
		}
		for _, e := range thing.b {
			sum += uint64(e)
		}
		for _, e := range thing.c {
			sum += uint64(e)
		}
		for _, e := range thing.d {
			sum += uint64(e)
		}
		for _, e := range thing.e {
			sum += uint64(e)
		}
		sum += uint64(thing.f)
	}
	duration := time.Since(start)

	fmt.Println(sum)
	fmt.Println("Took " + strconv.FormatInt(duration.Milliseconds(), 10) + "ms")
}
