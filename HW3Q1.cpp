/*
Steve Gonzalez
CIS 2541-003
03/06/2018
HW3 Q1

This program uses the freeFall function to display the 
distances an object in free fall has traveled after
one second intervals
*/

#include <iostream>

using namespace std;

// Function Prototype
double freeFall(int time = 0);

const double GRAVITY = 5.32;			// Global constant for force of gravity

int main()
{
	// Call the freeFall function with values 0 through 20
	for (int counter = 0; counter <= 20; ++counter)
	{
		double distance = freeFall(counter);
		cout << "After " << counter << " seconds ";
		cout << "the object has fallen " << distance << " feet." << endl;
	}

	system("PAUSE");
	return 0;
}
/*
Function name:	freeFall
Parameters:		Integer - time in seconds
Returns:		Double - Distance object has fallen
Descr:
	This function takes an integer argument representing the
	elapsed time in seconds. The function calculates the distance
	an object in free fall will have fallen in that elasped time
	and returns it.
*/
double freeFall(int time)
{
	// Distance fallen = 0.5 * Force of Gravity * Time^2
	return (0.5 * GRAVITY * (time * time));
}