/*
Steve Gonzalez
CIS 2541-003
02/23/2018
HW2 Q3

This program will prompt the user for an integer and then return the sum
of all integers from 1 to the user input
Uses a validation loop to prevent invalid input
*/

#include <iostream>

using namespace std;

int main()
{
	// Prompt the user for input
	cout << "This program will sum all integers from 1 to n" << endl;
	cout << "Please enter a positive integer value for n: ";
	int input;
	cin >> input;

	// Validation loop to prevent negative input
	while (input < 0)
	{
		cout << "You entered a negative integer" << endl;
		cout << "Please enter a positive integer value for n: ";
		cin >> input;
	}
	
	int sum = 0;						// Variable to store sum of integers

	// Loop to sum all integers from 1 to user input
	for (int count = 1; count <= input; ++count)
	{
		sum += count;
	}

	// Display results
	cout << "The sum of all integers from 1 to " << input << " is: " << sum << endl;

	system("PAUSE");
	return 0;
}