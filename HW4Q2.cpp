/*
Steve Gonzalez
CIS 2541-003
04/16/2018
HW4 Q2
*/

#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
int getMonth(string input);
string getDay(string input);
string getYear(string input);
string convertMonthToString(int month);

int main()
{
	// Prompt the user for a date with correct format
	cout << "Enter a date of the form mm@dd@yyyy." << endl;
	string input;
	cin >> input;

	// Call getDay fucntion to extract the substring for the day of the month
	string day = getDay(input);
	
	// Call getYear function to extract the substring for the year
	string year = getYear(input);

	// Call getMonth function to extract the month value
	int month = getMonth(input);

	// Convert the numberical month value to a string
	string outputMonth = convertMonthToString(month);

	// Concatenate the individual strings to produce the output
	string result = day + " " + outputMonth + " " + year;

	// Display the result
	cout << "You entered the date: " << result << endl;

	system("PAUSE");
	return 0;
}

/***********************************************
Function definition for the getDay Function
This function accepts a date as a string of the 
format mm@dd@yyyy and returns the substring at
positions 3 & 4 which corresponds to the day of 
the month
************************************************/
string getDay(string input)
{
	string day = input.substr(3, 2);
	return day;
}

/***********************************************
Function definition for the getMonth Function
This function accepts a date as a string of the
format mm@dd@yyyy and returns the substring at
positions 0 & 1 which corresponds to the month
************************************************/
int getMonth(string input)
{
	string month = input.substr(0, 2);
	return stoi(month);
}

/***********************************************
Function definition for the getYear Function
This function accepts a date as a string of the
format mm@dd@yyyy and returns the substring at
positions 8 & 9 which corresponds to the year
************************************************/
string getYear(string input)
{
	string year = input.substr(8, 2);
	return year;
}

/********************************************************
Function definition for the convertMonthToString Function
This function accepts an integer in the range [1,12]
and uses a switch statement to determine the month of the
year represented by the integer input. The month is 
returned as a C++ string
*********************************************************/
string convertMonthToString(int month)
{
	string outputMonth;
	switch (month)
	{
	case 1: outputMonth = "January";
		break;
	case 2: outputMonth = "February";
		break;
	case 3: outputMonth = "March";
		break;
	case 4: outputMonth = "April";
		break;
	case 5: outputMonth = "May";
		break;
	case 6: outputMonth = "June";
		break;
	case 7: outputMonth = "July";
		break;
	case 8: outputMonth = "August";
		break;
	case 9: outputMonth = "September";
		break;
	case 10: outputMonth = "October";
		break;
	case 11: outputMonth = "November";
		break;
	case 12: outputMonth = "December";
		break;
	}

	return outputMonth;
}