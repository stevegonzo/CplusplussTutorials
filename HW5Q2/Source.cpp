/*
Steve Gonzalez
CIS 2541-003
05/09/2018
HW5 Q2
*/

#include <iostream>
#include "Date.h"

int main()
{
	// Create an instance of the Date class
	Date newDate;
	// Create an instance of the Date class using the constructor
	Date newerDate(2, 4, 10, 1990);

	// Prompt the user to set the attributes of the Date object
	std::cout << "Enter an integer 1-7 to represent the day of the week." << std::endl;
	std::cout << "1 = Sunday, 2 = Monday, 3 = Tuesday, etc..." << std::endl;
	int inputDayOfWeek;
	std::cin >> inputDayOfWeek;
	newDate.setDayOfWeek(inputDayOfWeek);
	std::cout << "Enter an integer 1-12 to represent the month." << std::endl;
	int inputMonth;
	std::cin >> inputMonth;
	newDate.setMonth(inputMonth);
	std::cout << "Enter an integer 1-31 to represent the day of the month." << std::endl;
	int inputDay;
	std::cin >> inputDay;
	newDate.setDay(inputDay);
	std::cout << "Enter the year (Must be 1900 or later)" << std::endl;
	int inputYear;
	std::cin >> inputYear;
	newDate.setYear(inputYear);

	// Print the Date object in all three formats
	std::cout << "Here is the date you entered:" << std::endl;
	newDate.printFormatOne();
	newDate.printFormatTwo();
	newDate.printFormatThree();
	std::cout << std::endl << std::endl;

	// Print the second Date object in all three formats
	std::cout << "Here is the date the system created:" << std::endl;
	newerDate.printFormatOne();
	newerDate.printFormatTwo();
	newerDate.printFormatThree();


	system("PAUSE");
	return 0;
}