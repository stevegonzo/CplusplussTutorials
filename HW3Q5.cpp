/*
Steve Gonzalez
CIS 251-003
03/19/2018
HW3 Q5

This program generates a random lottery ticket with 4 integers
from 1 to 5. The program prompt the user to enter 4 integers to 
create their own lottery ticket. The user's ticket is then
compared to the winning ticket and the number of matching 
numbers is displayed.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Funtion Prototypes
void getUserTicket(int userTicket[], int arraySize);
void generateWinningTicket(int winningTicket[], int arraySize);
int numberOfMatchingElements(int array1[], int array2[], int arraySize);

int main()
{	
	const int ARRAY_SIZE = 4;			// Lottery ticket has four integers
	int userTicket[ARRAY_SIZE];			// Array to store user ticket numbers

	// Get user ticket
	getUserTicket(userTicket, ARRAY_SIZE);
	
	int winningTicket[ARRAY_SIZE];		// Array to store winning ticket numbers

	// Generate winning ticket
	generateWinningTicket(winningTicket, ARRAY_SIZE);

	// Compare user ticket to winning ticket
	int numberOfMatches = numberOfMatchingElements(userTicket, winningTicket, ARRAY_SIZE);

	// Display the User's ticket
	cout << endl  << "--------------------------" << endl;
	cout << "Your ticket: ";
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		cout << userTicket[i];
	}

	// Display the winning ticket
	cout << endl << "--------------------------" << endl;
	cout << "Winning ticket: ";
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		cout << winningTicket[i];
	}

	// Display number of matches
	cout << endl << "---------------------------" << endl;
	cout << "You matched " << numberOfMatches << " numbers." << endl;

	if (numberOfMatches == 4)
	{
		// User picked the winning numbers
		cout << "\aCongratulations! You won the lottery!" << endl;
	}

	system("PAUSE");
	return 0;
}

/********************************************************
Function definition for getUserTicket
This function prompts the user to enter integers to fill
an array representing a lottery ticket.
It uses a validation loop to ensure the inputs are in 
the acceptable range.
*********************************************************/
void getUserTicket(int userTicket[], int arraySize)
{
	// Prompt the user to enter each number on the ticket
	for (int i = 0; i < arraySize; ++i)
	{
		cout << "Enter the number on the ticket in position " << i + 1 << ": ";
		cin >> userTicket[i];
		// Validation loop 
		while ((userTicket[i] < 1) || (userTicket[i] > 5))
		{
			cout << "Valid tickets contain numbers from 1 to 5." << endl;
			cout << "Enter the number on the ticket in position " << i + 1 << ": ";
			cin >> userTicket[i];
		}
	}
}

/********************************************************
Function definition for generateWinningTicket
This function uses the random number fuction to fill an
array representing the winning lottery ticket.
*********************************************************/
void generateWinningTicket(int winningTicket[], int arraySize)
{
	// Get the system time
	unsigned seed = time(0);

	// Seed the random number generator
	srand(seed);

	// Ticket numbers are between 1 and 5
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 5;

	// Generate random numbers and fill the array
	for (int i = 0; i < arraySize; ++i)
	{
		winningTicket[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	}
}

/********************************************************
Function definition for numberOfMatchingElements
This function compares each element of two arrays and 
returns the number of elements that are equal and in the
same position in each array.
*********************************************************/
int numberOfMatchingElements(int array1[], int array2[], int arraySize)
{
	int numberOfMatches = 0;			// Variable to store number of matching elements
	for (int i = 0; i < arraySize; ++i)
	{
		if (array1[i] == array2[i])
		{
			++numberOfMatches;
		}
	}
	return numberOfMatches;
}