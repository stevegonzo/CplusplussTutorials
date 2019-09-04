/*
Steve Gonzalez
CIS 2541-003
03/20/2018
HW3 Q4

This program prompts the user to enter 9 integer values to
fill a 3x3 array. The program calls the isMagicSquare function
to check whether the integers entered are a magic square and
displays the result.
*/

#include <iostream>

using namespace std;

// Global Constants for Array Size
const int ROWS = 3;
const int COLS = 3;

// Function Prototype
bool isMagicSquare(const int[][COLS], int rows);

int main()
{
	int userArray[ROWS][COLS];			// Integer array to store user input
	// Prompt user for input
	cout << "Please enter integer values to fill a 3x3 grid." << endl;
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			cout << "Enter an integer from 1-9." << endl;
			cin >> userArray[i][j];
		}
	}

	// Check the array for magic sqaure
	bool magicSquare = isMagicSquare(userArray, ROWS);

	// Display user's array
	cout << "Your Grid: " << endl;
	for (int i = 0; i < ROWS; ++i)
	{
		cout << userArray[i][0] << userArray[i][1] << userArray[i][2] << endl;
	}

	// Display status of array
	if (magicSquare)
	{
		cout << "Your grid is a magic sqaure!" << endl;
	}
	else
	{
		cout << "Your grid is not a magic square." << endl;
	}

	system("PAUSE");
	return 0;
}

/*********************************************************
Function Definition for isMagicSqaure
This functions accepts a 2-D array as a parameter and 
determines if it is a magic square. A magic square is a
grid in which every row, column and diagonal have the same
sum. The result is returned as a boolean value.
*********************************************************/
bool isMagicSquare(const int userArray[][COLS], int rows)
{
	bool magicSquare = false;			// Flag variable

	// Arrays to store the sum of each row and column
	int rowSums[ROWS];
	int colSums[ROWS];


	// Sum each row
	for (int i = 0; i < rows; ++i)
	{
		int rowTotal = 0;				// The total sum of each row of integers

		for (int j = 0; j < COLS; ++j)
		{
			rowTotal += userArray[i][j];
		}

		// Store the row total in the array
		rowSums[i] = rowTotal;
	}

	// Sum each column
	for (int j = 0; j < COLS; ++j)
	{
		int colTotal = 0;				// The total sum of each column of integers

		for (int i = 0; i < rows; ++i)
		{
			colTotal += userArray[i][j];
		}

		// Store the column total in the array
		colSums[j] = colTotal;
	}

	// Sum the top left to bottom right diagonal [0,0], [1,1], etc
	int diagonalTotal = 0;				// The total sum of the diagonal
	for (int i = 0; i < rows; ++i)
	{
		diagonalTotal += userArray[i][i];
	}

	// Store the sum of the diagonal
	int diagonal1Sum = diagonalTotal;

	// Sum the top right to bottom left diagonal [0,COLS-1], [1, COLS-2], etc
	diagonalTotal = 0;					// Reset the diagonal total
	for (int i = 0; i < rows; ++i)
	{
		diagonalTotal += userArray[i][(COLS-1) - i];
	}

	// Store the sum of the diagonal
	int diagonal2Sum = diagonalTotal;

	// Compare the row and column arrays
	bool rowsAndColumnsEqual = false;
	for (int i = 0; i < rows; ++i)
	{
		// If the every element is equal, the rows and columns have the same sum
		if (rowSums[i] == colSums[i])
		{
			rowsAndColumnsEqual = true;
		}
		else
		{
			rowsAndColumnsEqual = false;
		}
	}

	// Now check the diagonals
	bool diagonalsEqual = false;
	if ((diagonal1Sum == rowSums[0]) && diagonal2Sum == rowSums[0])
	{
		diagonalsEqual = true;
	}

	// Final check for magic square
	if (rowsAndColumnsEqual && diagonalsEqual)
	{
		magicSquare = true;
	}
	
	return magicSquare;
}