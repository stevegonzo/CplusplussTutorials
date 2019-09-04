/*
Steve Gonzalez
CIS 2541-003
02/02/2018

This program will calculate the sum of two given integers and display
the mathematical expression
*/

#include <iostream>

using namespace std;

int main()
{
	int operand1 = 42;
	int operand2 = 57;
	int result = operand1 + operand2; 

	// display mathematical expression and result
	cout << operand1 << " + " << operand2 << " = " << result << endl;

	system("PAUSE");
	return 0;
}