#pragma once
/*
Steve Gonzalez
CIS 2541-003
05/09/2018
HW5 Q3
*/

#include <string>

class Dollars
{
public:
	Dollars();
	Dollars(float dollarAmount);
	void setDollarAmount(float dollarAmount);
	void Print();

private:
	float dollars;
	static std::string lessThan20[20];
	static std::string tens[10];
	static std::string hundred;
	static std::string thousand;
};


