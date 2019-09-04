/*
Steve Gonzalez
CIS 2541-003
04/16/2018
HW4 Q4
*/

#include <iostream>

using namespace std;

// Function Protoype
int swapPlacesAndAdd(int* x, int* y);

int main()
{
	// Prompt the user to enter an integer
	cout << "Enter an integer: ";
	int input1;
	cin >> input1;

	int* x = &input1;					// Pointer to user input 1

	// Prompt the user for another integer
	cout << "Enter another integer: ";
	int input2;
	cin >> input2;

	int* y = &input2;					// Pointer to user input 2

	// Display user input with current memory addresses
	cout << *x << " is stored in address " << x << endl;
	cout << *y << " is stored in adress " << y << endl;

	// Call swapPlacesAndAdd to swap the storage location of the ints
	// Store the sum in an integer variable
	cout << "Swapping memory addresses..." << endl;
	int sum = swapPlacesAndAdd(x, y);

	// Display the user input with new memory addresses
	cout << *x << " is stored in address " << x << endl;
	cout << *y << " is stored in address " << y << endl;

	// Display the sum of the inputs
	cout << "Their sum is " << sum << endl; 

	system("PAUSE");
	return 0;
}

/****************************************
Function Definition for swapPlacesAnAdd
This function accepts two integer pointers
and swaps the data stored at each memory 
address. The data is summed and returned
as an integer
****************************************/
int swapPlacesAndAdd(int* x, int*y)
{
	int temp= *x;
	*x = *y;
	*y = temp;
	return (*x + *y);
}