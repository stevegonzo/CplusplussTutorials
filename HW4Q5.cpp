/*
Steve Gonzalez
CIS 2541-003
04/17/2018
HW4 Q5
*/

#include <cstring>
#include <iostream>

using namespace std;

//Function Prototypes
char* reverseC_String(const char* strPtr, int size);
void displayC_String(const char cstring[], int size);

int main()
{
	// Constant for C-String size
	const int SIZE = 20;

	// Define 3 C-Strings
	char test1[SIZE] = "ABCDEFGHIJKLMNOPQRS";
	char test2[SIZE] = "1234567890123456789";
	char test3[SIZE] = "MrOwlAteMyMetalWorm";

	// Define pointers to accept new C-Strings
	char* string1 = nullptr;
	char* string2 = nullptr;
	char* string3 = nullptr;

	// Create new C-Strings by reversing existing C-Strings
	string1 = reverseC_String(test1, SIZE);
	string2 = reverseC_String(test2, SIZE);
	string3 = reverseC_String(test3, SIZE);

	// Display the original C-Strings
	cout << "Here are the original strings:" << endl;
	displayC_String(test1, SIZE);
	displayC_String(test2, SIZE);
	displayC_String(test3, SIZE);

	// Display reversed C-Strings
	cout << "The strings displayed in reverse order:" << endl;
	displayC_String(string1, SIZE);
	displayC_String(string2, SIZE);
	displayC_String(string3, SIZE);

	// Free dynamically allocated memory
	delete [] string1;
	delete [] string2;
	delete [] string3;
	string1 = nullptr;
	string2 = nullptr;
	string3 = nullptr;

	system("PAUSE");
	return 0;
}

char* reverseC_String(const char* strPtr, int size)
{
	// Create a pointer for a new C-String
	char* newC_String = nullptr;

	// Allocate new C-String
	newC_String = new char[size];

	// Copy the input C-String into the new C-String in reverse order
	// Do not include the null terminator
	for (int i = 0; i < (size-1); ++i)
	{
		newC_String[(size - 2) - i] = strPtr[i];
	}

	// Add the null terminator to the new C-String
	newC_String[size - 1] = '\0';

	// Return a pointer to the new C-String
	return newC_String;
}

void displayC_String(const char cstring[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << cstring[i];
	}
	cout << endl;
}