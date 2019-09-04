/*
Steve Gonzalez
CIS 2541-003
02/23/2018
HW2 Q4

This program will display the number of calories burned running
on a tredmill in 5 minute intervals
*/

#include <iostream>

using namespace std;

int main()
{
	// Display program function to user
	cout << "This program will calculate the amount of calories burned ";
	cout << "\nwhile running on a treadmill." << endl;
	system("PAUSE");

	const float CALORIES_PER_MINUTE = 5.4f;		// Calories burned per minute

	// Loop to display total calories burned every 5 minutes for a total of 30 minutes
	for (int count = 1; count <= 30; ++count)
	{
		if (count % 5 == 0)
		{
			// After each 5 minute interval
			// Calculate amount of calories burned
			float caloriesBurned = count * CALORIES_PER_MINUTE;
			cout << "After " << count << " minutes ";
			cout << "you burn " << caloriesBurned << " calories" << endl;
		}
	}

	system("PAUSE");
	return 0;
}