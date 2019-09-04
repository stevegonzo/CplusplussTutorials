/*
Steve Gonzalez
CIS 2541-003
02/02/2018

This program will caluclate the average of a given set of numbers
and display the result
*/

#include <iostream>

using namespace std;

int main()
{
	const int NUM_OPERANDS = 5; // number of operands in average

	// operands
	float num1 = 28.0;
	float num2 = 32.0;
	float num3 = 37.0;
	float num4 = 24.0;
	float num5 = 33.0;

	// calculate average
	float average = (num1 + num2 + num3 + num4 + num5) / NUM_OPERANDS;

	// display average
	cout << "The average of the set of numbers is: " << average << endl;

	system("PAUSE");

	return 0;

}