package main

import (
	"fmt"
	"time"
)

const conferenceTickets = 50

var conferenceName = "GO Conference"
var remainingTickets = 50
var bookings = make([]UserData, 0)

type UserData struct {
	firstName string
	lastName  string
	email     string
	tickets   int
}

func main() {

	fmt.Println("Welcome to", conferenceName, "booking applications")
	greetUsers()

	//var bookings = [50]string{}

	// var bookings [50]string

	for len(bookings) < 50 && remainingTickets > 0 {

		firstName, lastName, email, userTickets := getUserInput()
		isValidName, isValidEmail, isValidTickets := validateUserInput(firstName, lastName, email, userTickets, remainingTickets)

		if userTickets > remainingTickets || !isValidEmail || !isValidName || !isValidTickets {

			if !isValidEmail {
				fmt.Println("Email is Invalid")
			}
			if !isValidName {
				fmt.Println("First name or last name is Invalid")
			}
			if !isValidTickets {
				fmt.Println("Invalid Tickets")
			}
			if userTickets > remainingTickets {
				fmt.Printf("we only have %v tickets remaining, so you can't book %v tickets\n", remainingTickets, userTickets)
			}
			continue
		}

		bookTicket(userTickets, firstName, lastName, email)
		printFirstName()

		if remainingTickets <= 0 {
			fmt.Println("Our Conference tickets has been sold out!")
			break
		}
	}
}

func greetUsers() {
	fmt.Printf("Welcome to %v booking application\n", conferenceName)
	fmt.Printf("We have a total of %v tickets and %v tickets are still available.\n", conferenceTickets, remainingTickets)

	fmt.Println("Get your tickets here to attend")

}

func printFirstName() {
	fmt.Printf("These are all our bookings : ")
	fmt.Println()
	for _, booking := range bookings {
		// var name = strings.Fields(booking)
		// fmt.Println(booking["firstName"])
		fmt.Println(booking.firstName)
	}
}

func getUserInput() (string, string, string, int) {
	fmt.Println("Enter your first name")
	var firstName string
	fmt.Scan(&firstName)

	fmt.Println("Enter you last name")
	var lastName string
	fmt.Scan(&lastName)

	fmt.Println("Enter your email address")
	var email string
	fmt.Scan(&email)

	fmt.Println("How many tickets to book")
	var userTickets int
	fmt.Scan(&userTickets)

	return firstName, lastName, email, userTickets
}

func bookTicket(userTickets int, firstName string, lastName string, email string) {
	remainingTickets -= userTickets

	var userData = UserData{
		firstName: firstName,
		lastName:  lastName,
		email:     email,
		tickets:   userTickets,
	}

	// userData["firstName"] = firstName
	// userData["lastName"] = lastName
	// userData["email"] = email
	// userData["tickets"] = strconv.FormatInt(int64(userTickets), 10)

	// bookings = append(bookings, firstName+" "+lastName)

	bookings = append(bookings, userData)

	go sendTicket(userTickets, firstName, email)

	fmt.Printf("%v %v Booked %v tickets. You will be receiving the softcopy of tickets to you %v \n", firstName, lastName, userTickets, email)
	fmt.Printf("%v tickets remaining for %v\n", remainingTickets, conferenceName)
}

func sendTicket(userTickets int, firstName string, email string) {
	ticket := fmt.Sprintf("%v tickets for %v", userTickets, firstName)

	time.Sleep(10 * time.Second)
	fmt.Println("#########################")
	fmt.Printf("Sending ticket %v to email address %v\n", ticket, email)
	fmt.Println("#########################")
}
