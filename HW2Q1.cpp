/*
Steve Gonzalez
CIS 2541-003
02/13/2018 - Updated 02/27/2017
HW2Q1

This program will prompt the user to enter a number of seconds and will then
convert it to days, hours and minutes. The result will then be displayed on
the console
*/

#include <iostream>

using namespace std;

int main()
{

	// Prompt the user for input
	cout << "This program will convert seconds into days, hours and minutes." << endl;
	cout << "Please enter the amount of seconds you would like to have converted: ";
	double numSeconds;					// Variable to store the user input
	cin >> numSeconds;

	// Constants for number of seconds in a day, hour and minute
	const int SECONDS_IN_DAY = 86400;
	const int SECONDS_IN_HOUR = 3600;
	const int SECONDS_IN_MINUTE = 60;

	const int HOURS_IN_DAY = 24;		// Number of hours in a day
	const int MINUTES_IN_DAY = 1440;	// Number of minutes in a day
	const int MINUTES_IN_HOUR = 60;		// Number of minutes in an hour

	// Calculate the number of days
	// numDays is truncated
	int numDays = numSeconds / SECONDS_IN_DAY;

	// Calculate the number of hours and subtract the number of hours in numDays
	// numHours is truncated
	int numHours = (numSeconds / SECONDS_IN_HOUR) - (numDays * HOURS_IN_DAY);

	// Calculate the number of minutes and subtract the number of minutes
	// In numDays and numHours
	double numMinutes = (numSeconds / SECONDS_IN_MINUTE) - (numDays * MINUTES_IN_DAY)\
		- (numHours * MINUTES_IN_HOUR);

	// Display results
	cout << numSeconds << " seconds is: " << numDays << " day(s) "\
		<< numHours << " hour(s) and " << numMinutes << " minute(s). " << endl;

	system("PAUSE");

	return 0;
}