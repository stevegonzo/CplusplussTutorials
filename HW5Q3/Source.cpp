/*
Steve Gonzalez
CIS 2541-003
05/09/2018
HW5 Q3
*/

#include <iostream>
#include "Dollars.h"

int main()
{
	Dollars newAmount;
	char again;
	do
	{
		// Prompt the user to enter a dollar amount
		std::cout << "Please enter a dollar amount less than $10,000.00: $";
		float dollarAmount;
		std::cin >> dollarAmount;

		// Update the member variable
		newAmount.setDollarAmount(dollarAmount);

		// Display the dollar amount in English
		newAmount.Print();

		// Prompt the user to continue or exit
		std::cout << "Enter another amount (Y/N)?" << std::endl;
		std::cin >> again;
	
	} while ((again == 'Y') || (again == 'y'));

	return 0;
}