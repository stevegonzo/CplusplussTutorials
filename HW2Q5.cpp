/*
Steve Gonzalez
CIS 2541-003
02/23/2018 - Updated 2/27/2018
HW2 Q5

This program will generate a random number in the range 1-100
and will prompt the user to guess the number. The program will
record the number of guesses and display the result when the 
user successfully guesses the number
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Get the system time
	unsigned seed = time(0);

	// Seed the random number generator
	srand(seed);
	
	// Generate a random number in range 1-100
	const int MIN_VALUE = 1;			// Minimum for random number
	const int MAX_VALUE = 100;			// Maximum for random number
	int random = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

	// Prompt the user for first guess
	cout << "I've picked an integer between 1 and 100, can you guess it?" << endl;
	cout << "Enter a number: ";
	int guess;							// Variable to store user input
	cin >> guess;

	// Validation loop
	while ((guess < 1) || (guess > 100))
	{
		cout << "Oops! You must guess a number between 1 and 100." << endl;
		cout << "Enter a number: ";
		cin >> guess;
	}

	int numGuesses = 0;					// Variable to keep track of the number of guesses
	
	// Loop until the user guesses correctly
	while (guess != random)
	{
		if (guess < random)
		{
			// User guessed too low, prompt for another guess
			cout << "Too low! Guess again: ";
			cin >> guess;
			// Increment the number of guesses
			++numGuesses;
		}
		else
		{
			// User guessed too high, prompt for another guess
			cout << "Too high! Guess again: ";
			cin >> guess;
			// Increment the number of guesses
			++numGuesses;
		}
		
	}

	// User guessed correctly, increment number of guesses for correct guess
	++numGuesses;

	// Display number of attempts
	cout << "You got it! Great going! It took you " << numGuesses << " guesses." << endl;

	system("PAUSE");
	return 0;
}