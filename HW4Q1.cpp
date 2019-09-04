/*
Steve Gonzalez
CIS 2541-003
04/17/2018
HW4 Q1
*/

#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

// Function Prototypes
string getPassword();
bool isLongEnough(string input, int length);
bool containsCapitalLetter(string input);
bool containsLowercaseLetter(string input);
bool containsTwoSpecialCharacters(string input, char c);
bool containsAdjacentDigits(string input);

// Constants for password requirements
const int PASSWORD_LENGTH = 10;
const char SPECIAL_CHAR = '$';

int main()
{

	// Call getPassword function to prompt the user to for a password
	string password = getPassword();

	bool longEnough = isLongEnough(password, PASSWORD_LENGTH);
	bool capital = containsCapitalLetter(password);
	bool lowercase = containsLowercaseLetter(password);
	bool special = containsTwoSpecialCharacters(password, SPECIAL_CHAR);
	bool twoDigits = containsAdjacentDigits(password);

	bool goodPassword = (longEnough && capital && lowercase && special && twoDigits);

	while (goodPassword == false)
	{
		cout << "Your password is invalid." << endl;
		if (longEnough == false)
		{
			cout << "The password must be AT LEAST " << PASSWORD_LENGTH << " characters long." << endl;
		}
		if (capital == false)
		{
			cout << "The password must contain AT LEAST one capital letter." << endl;
		}
		if (lowercase == false)
		{
			cout << "The password must contain AT LEAST one lowercase letter." << endl;
		}
		if (special == false)
		{
			cout << "The password must contain EXACTLY two " << SPECIAL_CHAR << " characters." << endl;
		}
		if (twoDigits == false)
		{
			cout << "The password must contain AT LEAST one pair of adjacent digits." << endl;
		}
		
		password = getPassword();

		longEnough = isLongEnough(password, PASSWORD_LENGTH);
		capital = containsCapitalLetter(password);
		lowercase = containsLowercaseLetter(password);
		special = containsTwoSpecialCharacters(password, SPECIAL_CHAR);
		twoDigits = containsAdjacentDigits(password);

		goodPassword = (longEnough && capital && lowercase && special && twoDigits);
	}


	cout << "Your username and password are valid! Thank you!" << endl;

	system("PAUSE");
	return 0;
}

string getPassword()
{
	// Prompt the user to create a username and password
	cout << "Please create a username for your new account: ";
	string username;
	cin >> username;
	cout << "---------------------------------------------------------" << endl;
	cout << "Passwords must meet the followin criteria:" << endl;
	cout << "-must be AT LEAST " << PASSWORD_LENGTH << " characters long" << endl;
	cout << "-must contain AT LEAST one uppercase letter" << endl;
	cout << "-must contain AT LEAST one lowercase letter" << endl;
	cout << "-must contain EXACTLY two '$' symbols" << endl;
	cout << "-must contain AT LEAST one pair of adjacent digits" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Please create a password for your account: ";
	string password;
	cin >> password;

	return password;
}
/*****************************************
Function definition for isLongEnough
Returns true if the length of the string
parameters is greater than or equal to the
integer parameter
*****************************************/
bool isLongEnough(string input, int length)
{
	return (input.length() >= length);
}
/*********************************************
Function definition for containsCapitalLetter
Returns true if the string paramenter contains
at least one uppercase character
**********************************************/
bool containsCapitalLetter(string input)
{
	bool capital = false;				// True if the string contains an uppercase character
	
	// Loop through each character of the string
	for (int i = 0; i < input.length(); ++i)
	{
		// If the character is a capital letter, update the boolean flag and exit the loop
		if (isupper(input[i]))
		{
			capital = true;
			break;
		}
	}
	
	return capital;
}
/**********************************************
Function definition for containsLowercaseLetter
Returns true if the string paramter contains
at least one lowercase character
**********************************************/
bool containsLowercaseLetter(string input)
{
	bool lowercase = false;				// True if the string contains a lowercase character

	// Loop through each character of the string
	for (int i = 0; i < input.length(); ++i)
	{
		// If the character is a lowercase character, update the boolean flag and exit the loop
		if (islower(input[i]))
		{
			lowercase = true;
			break;
		}
	}

	return lowercase;
}
/***************************************************
Function definition for containsTwoSpeicalCharacters
The function counts the number of instances of the
character parameter. If the string parameter contains
exactly two instances of the character, the function
retunrs true
***************************************************/
bool containsTwoSpecialCharacters(string input, char c)
{
	bool special = false;				// True if the string contains EXACTLY two instances of char c
	int count = 0;						// The number of instances of char c

	// Loop through each character of the string
	for (int i = 0; i < input.length(); ++i)
	{
		// If the character is equal to char c, increment the count
		if (input[i] == c)
		{
			++count;
		}
	}
	if (count == 2)
	{
		special = true;
	}
	return special;
}
/*********************************************
Function definition for containsAdjacentDigits
This function checks every pair of adjacent
characters to determine if they are both digits.
If the string parameter contains one pair of 
adjacent digits, it returns true
*********************************************/
bool containsAdjacentDigits(string input)
{
	bool twoDigits = false;				// True if the string cotains adjecent digits

	// Loop through each character of the string
	for (int i = 0; i < (input.length()-1); ++i)
	{
		// If the adjacent characters are both digits, update the boolean flag and exit the loop
		if (isdigit(input[i]) && isdigit(input[i + 1]))
		{
			twoDigits = true;
			break;
		}
	}
	return twoDigits;
}