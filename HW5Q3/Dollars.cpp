/*
Steve Gonzalez
CIS 2541-003
05/09/2018
HW5 Q3
*/

#include <iostream>
#include <math.h>
#include <string>
#include "Dollars.h"

// Static Member Variables
std::string Dollars::lessThan20[20] = { "zero", "one", "two", 
										"three", "four", "five",
										"six", "seven", "eight", 
										"nine", "ten", "eleven",
										"twelve", "thirteen", "fourteen", 
										"fifteen", "sixteen", "seventeen",
										"eighteen", "nineteen" };
std::string Dollars::tens[10] = { "zero", "ten", "twenty", "thirty",
								 "fourty", "fifty", "sixty",
								 "seventy", "eighty", "ninety" };
std::string Dollars::hundred = "hundred";
std::string Dollars::thousand = "thousand";

// Default Constructor - delegates to main constructor
Dollars::Dollars()
	: Dollars(0.0)
{
	// Nothing to do here
}

// Main Constructor
Dollars::Dollars(float dollarAmount)
{
	setDollarAmount(dollarAmount);
}

void Dollars::setDollarAmount(float dollarAmount)
{
	while ((dollarAmount < 0.0f) || (dollarAmount >= 10000.00f))
	{
		std::cout << "Please enter a dollar amount less than $10,000.00: $";
		std::cin >> dollarAmount;
	}

	// The input is valid, set the member variable
	dollars = dollarAmount;
}

void Dollars::Print()
{
	float decimal;
	float wholeDollars;

	// Break dollars into decimal part and whole dollars
	decimal = modf(dollars, &wholeDollars);

	// Get the last three and last two digits of the whole dollars
	int threeDigits = static_cast<int>(wholeDollars) % 1000;
	int twoDigits = threeDigits % 100;
	// Extract each digit from the whole dollars
	int thousandsPlace = static_cast<int>(wholeDollars) / 1000;
	int hundredsPlace = threeDigits / 100;
	int tensPlace = twoDigits / 10;
	int onesPlace = twoDigits % 10;

	// Convert the decimal part of the dollar amount into whole cents
	decimal *= 100;
	int cents = round(decimal);
	
	// Extract each digit from cents
	int dimes = cents / 10;
	int pennies = cents % 10;

	// String variable for the English translation of the whole dollars
	std::string outputDollars;

	if (thousandsPlace != 0)
	{
		// If there is a digit in the thousands place add to the output string
		// The corresponding string from the static string array and the "thousand" string
		outputDollars += lessThan20[thousandsPlace];
		outputDollars += " ";
		outputDollars += thousand;
		outputDollars += " ";
	}

	if (hundredsPlace != 0)
	{
		// If there is a digit in the hundreds place add to the output string
		// The corresponding string from the static string array and the "hundred" string
		outputDollars += lessThan20[hundredsPlace];
		outputDollars += " ";
		outputDollars += hundred;
		outputDollars += " ";
	}

	if ((tensPlace == 1) && (onesPlace == 0))
	{
		// If the final two digits are 1 and 0, add "ten" to the output string
		outputDollars += tens[tensPlace];
	}
	else if ((tensPlace == 1) && (onesPlace != 0))
	{
		// The last two digits are less than twenty, add to the output string
		// The corresponiding string from the static string array
		outputDollars += lessThan20[twoDigits];
	}
	else if (tensPlace != 0)
	{
		// The last two digits are greater than 19
		outputDollars += tens[tensPlace];
		
		if (onesPlace != 0)
		{
			// Prevent adding "twenty zero", "thirty zero", etc to the output string
			outputDollars += " ";
			outputDollars += lessThan20[onesPlace];
		}
	}
	else
	{
		// The digit in the tens place is zero; add to the output string
		// The string from the static string array that corresponds to 
		// The last digit
		outputDollars += lessThan20[onesPlace];
	}

	// String variable for the English translation of the decimal portion
	std::string outputCents;

	if (dimes <= 1)
	{
		// The decimal portion is less than twenty, add to the output
		// String the corresponding string from the static string array
		outputCents += lessThan20[cents];
	}
	else
	{
		// Add to the output string the corresponding string from the 
		// static string arrays
		outputCents += tens[dimes];
		if (pennies != 0)
		{
			outputCents += " ";
			outputCents += lessThan20[pennies];
		}
	}

	// Display the amount in Enlgish
	std::cout << "You entered: " << std::endl;
	std::cout << outputDollars << " dollars and " << outputCents << " cents.";
	std::cout << std::endl;
}