package main

import (
	"fmt"

	"example.com/greetings"
)

func main() {
	message := greetings.Hello("ABS")
	fmt.Println(message)
}
