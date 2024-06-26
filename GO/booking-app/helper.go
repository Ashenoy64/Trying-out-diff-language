package main

import "strings"

func validateUserInput(firstName string, lastName string, email string, userTickets int, remainingTickets int) (bool, bool, bool) {
	isValidName := len(firstName) >= 2 && len(lastName) >= 2
	isValidEmail := strings.Contains(email, "@") && len(email) >= 4
	isValidTickets := userTickets > 0

	return isValidName, isValidEmail, isValidTickets
}
