/*
Steve Gonzalez
CIS 2541-003
03/14/2018
HW3 Q3

This program tests the printAllGreaterValues function using an
initialized integer array and an incrementing search value
*/

#include <iostream>

using namespace std;

// Function Prototype
void printAllGreaterValues(const int numbers[], int arraySize, int N);

int main()
{
	const int ARRAY_SIZE = 12;
	int numbers[ARRAY_SIZE] = { 5, 7, 9, 15, 19, 23, 34, 45, 58, 61, 70, 84 };

	// Prompt the user to enter the test interval
	cout << "Set the test interval: ";
	int interval;
	cin >> interval;

	for (int i = 0; i < 100; i += interval)
	{
		// Call the function using the loop counter variable as the search value
		printAllGreaterValues(numbers, ARRAY_SIZE, i);
	}
	
	system("PAUSE");
	return 0;
}

void printAllGreaterValues(const int numbers[], int arraySize, int N)
{
	cout << "The values in the array greater than " << N << " are:" << endl;
	// Check every value in array and test if it is greater than the search value
	for (int i = 0; i < arraySize; i++)
	{
		if (numbers[i] > N)
		{
			// Print the array element if it is greater than the search value
			cout << numbers[i] << endl;
		}
	}
}