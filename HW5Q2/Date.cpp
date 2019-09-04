/*
Steve Gonzalez
CIS 2541-003
05/09/2018
HW5 Q2
*/

#include <iostream>
#include <string>
#include "Date.h"

// Default constructor, delegated to the main constructor
Date::Date()
	:Date(1, 1, 1, 1900)
{
	// Nothing to do
}

// Constructor
Date::Date(int w, int m, int d, int y)
{
	setDayOfWeek(w);
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDayOfWeek(int inputWeekday)
{
	// Validation Loop
	while ((inputWeekday < 1) || (inputWeekday > 7))
	{
		std::cout << "The day of the week must be represented by an integer from 1 to 7." << std::endl;
		std::cout << "Please enter a value between 1 and 7." << std::endl;
		std::cin >> inputWeekday;
	}
	// Parameter is valid, go ahead and set field
	dayOfWeek = inputWeekday;
}

void Date::setMonth(int inputMonth)
{
	// Validation Loop
	while ((inputMonth < 1) || (inputMonth > 12))
	{
		std::cout << "The month must be represented by an integer from 1 to 12." << std::endl;
		std::cout << "Please enter a value between 1 and 12." << std::endl;
		std::cin >> inputMonth;
	}
	// Parameter is valid, go ahead and set field
	month = inputMonth;
}

void Date::setDay(int inputDay)
{
	// Validation Loop
	while ((inputDay < 1) || (inputDay > 31))
	{
		std::cout << "The day must be an integer between 1 and 31." << std::endl;
		std::cout << "Please enter a value between 1 and 31." << std::endl;
		std::cin >> inputDay;
	}
	// Parameter is valid, go ahead and set field
	day = inputDay;
}

void Date::setYear(int inputYear)
{
	// Validation Loop
	while (inputYear < 1900)
	{
		std::cout << "Years earlier than 1900 are invalid" << std::endl;
		std::cout << "Please enter a value greater than or equal to 1900." << std::endl;
		std::cin >> inputYear;
	}
	// Parameter is valid, go ahead and set field
	year = inputYear;
}

void Date::printFormatOne()
{
	char dayChar = ' ';

	switch (dayOfWeek)
	{
	case 1: dayChar = 'U';
		break;
	case 2: dayChar = 'M';
		break;
	case 3: dayChar = 'T';
		break;
	case 4: dayChar = 'W';
		break;
	case 5: dayChar = 'R';
		break;
	case 6: dayChar = 'F';
		break;
	case 7: dayChar = 'S';
	}
	std::cout << dayChar << "/";
	if (month < 10)
	{
		// If the month is a single digit, print a zero in front of it
		std::cout << "0";
	}
	std::cout << month << "/" << day << "/" << year << std::endl;
}

void Date::printFormatTwo()
{
	std::string dayString = " ";
	
	switch (dayOfWeek)
	{
	case 1: dayString = "Sunday";
		break;
	case 2: dayString = "Monday";
		break;
	case 3: dayString = "Tuesday";
		break;
	case 4: dayString = "Wednesday";
		break;
	case 5: dayString = "Thursday";
		break;
	case 6: dayString = "Friday";
		break;
	case 7: dayString = "Saturday";
	}

	std::string monthString = " ";

	switch (month)
	{
	case 1: monthString = "January";
		break;
	case 2: monthString = "February";
		break;
	case 3: monthString = "March";
		break;
	case 4: monthString = "April";
		break;
	case 5: monthString = "May";
		break;
	case 6: monthString = "June";
		break;
	case 7: monthString = "July";
		break;
	case 8: monthString = "August";
		break;
	case 9: monthString = "September";
		break;
	case 10: monthString = "October";
		break;
	case 11: monthString = "November";
		break;
	case 12: monthString = "December";
	}

	std::cout << dayString << ", " << monthString;
	std::cout << " " << day << ", " << year << std::endl;
}

void Date::printFormatThree()
{
	std::string dayString = " ";

	switch (dayOfWeek)
	{
	case 1: dayString = "Sunday";
		break;
	case 2: dayString = "Monday";
		break;
	case 3: dayString = "Tuesday";
		break;
	case 4: dayString = "Wednesday";
		break;
	case 5: dayString = "Thursday";
		break;
	case 6: dayString = "Friday";
		break;
	case 7: dayString = "Saturday";
	}

	std::string monthString = " ";

	switch (month)
	{
	case 1: monthString = "January";
		break;
	case 2: monthString = "February";
		break;
	case 3: monthString = "March";
		break;
	case 4: monthString = "April";
		break;
	case 5: monthString = "May";
		break;
	case 6: monthString = "June";
		break;
	case 7: monthString = "July";
		break;
	case 8: monthString = "August";
		break;
	case 9: monthString = "September";
		break;
	case 10: monthString = "October";
		break;
	case 11: monthString = "November";
		break;
	case 12: monthString = "December";
	}

	std::cout << day << " " << monthString << " " << year;
	std::cout << " is on a " << dayString << std::endl;
}