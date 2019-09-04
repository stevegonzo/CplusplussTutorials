/*
Steve Gonzalez
CIS 2541-003
02/13/2018
HW2Q2

This program will prompt the user for a month and year and display the number
of days in that month
*/

#include <iostream>

using namespace std;

int main()
{
	// Variables to store user input
	int month;
	int year;

	// Prompt the user for input
	cout << "This program will tell you how many days occurred in given month and year" << endl;
	cout << "Please enter the numeric value of a month (1-12): ";
	cin >> month;
	cin.ignore();
	cout << "Please enter a year: ";
	cin >> year;
	cout << endl;

	// Determine if the year entered was a leap year
	bool leapYear = false;				// Boolean flag
	if ((year % 100 == 0) && (year % 400 == 0))
	{
		// Years that are divisible by 100 are a leap year if they are 
		// Also divisible by 400
		leapYear = true;
	}
	else if ((year % 100 != 0) && (year % 4 == 0))
	{
		// Years that are not divisible by 100 are a leap year if they
		// Are also divisible by 4
		leapYear = true;
	}
	

	// Case of February in a leap year
	if (leapYear && (month == 2))
	{
		cout << "That month has 29 days.";
	}
	else
	{
		// Switch structure for all other months
		// Leap year is insignificant for number of days in every other month of the year
		switch (month)
		{
		case 1: cout << "That month has 31 days.";
			break;
		case 2: cout << "That month has 28 days.";
			break;
		case 3: cout << "That month has 31 days.";
			break;
		case 4: cout << "That month has 30 days.";
			break;
		case 5: cout << "That month has 31 days.";
			break;
		case 6: cout << "That month has 30 days.";
			break;
		case 7: cout << "That month has 31 days.";
			break;
		case 8: cout << "That month has 31 days.";
			break;
		case 9: cout << "That month has 30 days.";
			break;
		case 10: cout << "That month has 31 days.";
			break;
		case 11: cout << "That month has 30 days.";
			break;
		case 12: cout << "That month has 31 days.";
			break;
		default: cout << "You entered an invalid month. Enter a value 1-12.";
		}
	}
	cout << endl;

	system("PAUSE");
	return 0;
}