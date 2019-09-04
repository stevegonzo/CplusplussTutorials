/*
Steve Gonzalez
CIS 2541-003
04/17/2018
HW4 Q3
*/

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Prompt the user for an input string
	cout << "Enter a sentence with no spaces, in which " << endl;
	cout << "each new word begins with a capital letter." << endl;
	cout << "For example: ";
	cout << "SummerIsButAFewShortWeeksAway" << endl;
	string input;
	getline(cin, input);

	// Validate that the string is not empty
	while (input.empty() == true)
	{
		cout << "You did not type anything. Please try again." << endl;
		getline(cin, input);

		// Validate that the string contains no spaces
		while (input.find(' ', 0) != (string::npos))
		{
			cout << "Please enter a sentence with no spaces." << endl;
			getline(cin, input);
		}
	}

	// Get the size of the string
	int length = input.length();

	// Loop through each character of the string
	// Exclude the first character because it is the start of the 
	// sentence and should remain a capital letter 
	int i = 1;
	char a = input[i];
	while (i < length)
	{
		// If the character is capital, insert a space in the string at
		// the poistion of the character. Delete the capital character
		// and replace it with the lowercase character at the next position
		// then increment the position by two
		if (isupper(a) == true)
		{
			a = tolower(a);
			input.insert(i, 1, ' ');
			input.erase(i + 1, 1);
			input.insert(i + 1, 1, a);
			i+=2;
		}
		else
		{
			// A capital letter was not at position i, so move to the next character
			++i;
		}
		a = input[i];
		length = input.length();
	}

	// Display the new string with spaces
	cout << "Here is the sentence you entered with spaces added." << endl;
	cout << input << endl;

	system("PAUSE");
	return 0;
}