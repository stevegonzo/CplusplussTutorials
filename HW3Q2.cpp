/*
Steve Gonzalez
CIS 2541-003
03/06/2018
HW3 Q2

This program uses a modular approach to prompt the user for
several items of data: The number of rooms to be painted, the
square footage of each room, and the cost of the paint. The 
program will display the total number of gallons of paint 
required, the hours of labor required, the cost of the paint,
the total labor charges, and the total cost of the paint job.
*/

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Function Prototypes
int getNumRooms();
double getSquareFootage();
double getPaintPrice();
int calcAndDisplayGallons(double squareFootage);
double calcAndDisplayLabor(double squareFootage);
double calcAndDisplayPaintCost(int numGallons, double gallonCost);
double calcAndDisplayLaborCharge(double laborHours);
void calcAndDisplayTotalCharge(double paintCost, double laborCharge);

int main()
{
	// Get the number of rooms to be painted from the user
	int numRooms = getNumRooms();

	// Get the paint price from the user
	double paintPrice = getPaintPrice();

	double totalSquareFootage = 0.0;	// Variable to keep track of total SQ FT

	// Loop to get total sqaure footage of all rooms
	for (int count = 1; count <= numRooms; ++count)
	{
		cout << "--------------------------------" << endl;
		// Prompt the user for the sqaure footage of each individual room
		// using the getSquareFootage function
		cout << "Room " << count << endl;
		double squareFootage = getSquareFootage();
		// Accumulate the total square footage
		totalSquareFootage += squareFootage;
	}

	// Calculate and display the number of gallons needed
	int numGallons = calcAndDisplayGallons(totalSquareFootage);

	// Calculate and display the labor hours needed
	double laborHours = calcAndDisplayLabor(totalSquareFootage);

	// Calculate and display the cost of the paint
	double paintCost = calcAndDisplayPaintCost(numGallons, paintPrice);

	// Calculate and display the total labor charge
	double laborCharge = calcAndDisplayLaborCharge(laborHours);

	// Calculate and display the total charge for the paint job
	calcAndDisplayTotalCharge(paintCost, laborCharge);

	system("PAUSE");
	return 0;
}

/*
Function Name:		getNumRooms
Parameters:			None
Returns:			Integer - Number of rooms to be painted
Descr:
	This function prompts the user to enter how many rooms
	need to be painted. This function uses a validation loop
	to ensure a minimum of two rooms is entered.
	The input is then returned as an integer
*/
int getNumRooms()
{
	// Prompt the user for input
	cout << "Please enter the number of rooms to be painted (min. 2): ";
	int numRooms;						// Number of rooms to be painted
	cin >> numRooms;
	
	// Validation loop
	while (numRooms < 2)
	{
		// Display error message
		cout << "The minimum number of rooms is 2." << endl;
		cout << "Please enter the number of rooms to be painted: ";
		cin >> numRooms;
	}
	
	// Return the valid input
	return numRooms;
}

/*
Function Name:		getSquareFootage
Parameters:			None
Returns:			Double - Square footage of the room
Descr:
	This function prompts the user to enter the total square
	footage of the room. This function uses a validation loop
	to prevent negative input. The input is then returned as
	a double.
*/
double getSquareFootage()
{
	// Prompt the user for input
	cout << "Please enter the square footage of the room: ";
	double squareFootage;
	cin >> squareFootage;
	
	// Validation Loop
	while (squareFootage < 0.0)
	{
		// Display error message
		cout << "You must enter a postive value." << endl;
		cout << "Please enter the square footage of the room: ";
		cin >> squareFootage;
	}

	// Return the valid input
	return squareFootage;
}

/*
Function Name:		getPaintPrice
Paramters:			None
Returns:			Double - The price per gallon of paint
Descr:
	This function prompts the user for the price per
	gallon of paint. This function uses a validation loop
	to ensure a minimum value of $12 is entered. The input
	is then returned as a double.
*/
double getPaintPrice()
{
	// Prompt the user for input
	cout << "Enter the price per gallon of paint: $";
	double paintPrice;					// Price per gallon of paint
	cin >> paintPrice;

	// Validation Loop
	while (paintPrice < 12.0)
	{
		// Display error message
		cout << "The minimum price per gallon is $12.00." << endl;
		cout << "Please enter the price per gallon of paint: $";
		cin >> paintPrice;
	}

	// Return the valid input
	return paintPrice;
}

/*
Function Name:		calcAndDisplayGallons
Parameters:			Double - The total sqaure footage of all rooms
Returns:			None
Descr:
	This function  accepts an integer representing the total sqaure
	footage for all rooms to be painted. This function then calculates
	the total number of gallons of painted required based on the ratio
	of 1 gallon per 200 square feet. The result is displayed and 
	returned to the calling statement
*/
int calcAndDisplayGallons(double squareFootage)
{
	const double SQ_FT_PER_GALLON = 200.0;	
	int numGallons;						// Will hold number of gallons of paint required
	if (fmod(squareFootage, SQ_FT_PER_GALLON) != 0)
	{
		// If the division results in a remainder, round up the truncated value
		// Because paint must be purchased in whole gallons
		numGallons = (squareFootage / SQ_FT_PER_GALLON) +1;
	}
	else
	{
		// The total sqaure footage was divisible by SQ_FT_PER_GALLON
		// No rounding needed because no data was lost to truncation
		numGallons = (squareFootage / SQ_FT_PER_GALLON);
	}

	// Display the number of gallons
	cout << "The number of gallons of paint required for the paint job is ";
	cout << numGallons << endl;

	// Return the number of gallons 
	return numGallons;
}

/*
Function Name:		calcAndDisplayLabor
Parameters:			Double - The total square footage of all rooms
Returns:			Double - The total labor hours for the paint job
Descr:
	This function accepts a double value for the total square footage
	of all rooms in the paint job. This function then calculates the 
	total labor hours need for the job based on the ratio of 6 hours
	for every 200 square feet. The total labor hours is displayed
	and returned to the calling statement
*/
double calcAndDisplayLabor(double squareFootage) {
	const int SQ_FT_RATIO = 200;		// Amount of square footage for labor rate
	const int HRS_PER_200SQ_FT = 6;		// Labor hours required to paint 200 ft^2
	
	// Calculate labor hours
	double laborHours = (squareFootage / SQ_FT_RATIO) * HRS_PER_200SQ_FT;

	// Display the labor hours
	cout << setprecision(2) << fixed << showpoint;
	cout << "The total labor hours required for the paint job is ";
	cout << laborHours << " hours." << endl;

	// Return the labor hours
	return laborHours;
}

/*
Function Name:		calcAndDisplayPaintCost
Parameters:			Integer - The gallons of paint need for paint job
					Double - The cost of each gallon of paint
Returns:			None
Descr:
	This function accepts the number of gallons needed for the paint job
	and the price of each gallon of paint. This function will then calculate
	the total paint cost for the paint job. The result will be displayed 
	and returned to the calling statement
*/
double calcAndDisplayPaintCost(int numGallons, double gallonCost)
{
	// Calculate the total paint cost
	double paintCost = numGallons * gallonCost;
	
	// Display the paint cost
	cout << setprecision(2) << fixed << showpoint;
	cout << "The total cost of paint for the paint job is: $" << paintCost << endl;
	
	// Return the paint cost
	return paintCost;
}

/*
Function Name:		calcAndDisplayLaborCharge
Parameters:			Double - The total labor hours required
Returns:			Double - The total labor cost for the paint job
Descr:
	This function accepts the total number of labor hours for the paint
	job and calculated the total labor charge based on the rate: $20/hr.
	The result is then displayed and returned to the calling statement.
*/
double calcAndDisplayLaborCharge(double laborHours)
{
	const int COST_PER_HR = 20;			// Charge per hour of labor
	
	// Calculate total labor charge
	double laborCharge = laborHours * COST_PER_HR;

	// Display the labor charge
	cout << setprecision(2) << fixed << showpoint;
	cout << "The total labor charge for the paint job is: $";
	cout << laborCharge << endl;

	// Return the labor charge
	return laborCharge;
}

/*
Function Name:		calcAndDisplayTotalCharge
Paramters:			Double - The total cost of paint for the paint job
					Double - The total labor charge for the paint job
Returns:			None
Descr:
	This function accepts the total paint cost and total labor charge
	for the paint job and calculates the total charge for the paint job.
	The result is then displayed.
*/
void calcAndDisplayTotalCharge(double paintCost, double laborCharge)
{
	// Calculate total charge
	double totalCharge = paintCost + laborCharge;

	// Display the total charge
	cout << setprecision(2) << fixed << showpoint;
	cout << "The total charge for the paint job is: $" << totalCharge << endl;
}