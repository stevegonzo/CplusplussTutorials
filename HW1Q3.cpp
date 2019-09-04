/*
Steve Gonzalez
CIS 2541-003
02/02/2018

This program will display the amount of memory
used by several datatypes
*/

#include <iostream>

using namespace std;

int main()
{
	// variable declarations
	char testChar;
	int testInt;
	float testFloat;
	double testDouble;

	// display size of data types
	cout << "The size of a character is: " << sizeof(testChar) << " byte" << endl;
	cout << "The size of an integer is: " << sizeof(testInt) << " bytes" << endl;
	cout << "The size of a floating point is: " << sizeof(testFloat) << " bytes" << endl;
	cout << "The size of a double is: " << sizeof(testDouble) << " bytes" << endl;

	system("PAUSE");

	return 0;
}