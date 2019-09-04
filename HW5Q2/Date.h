#pragma once
/*
Steve Gonzalez
CIS 2541-003
05/09/2018
HW5 Q2
*/

class Date
{
public:
	Date();
	Date(int w, int m, int d, int y);
	void setDayOfWeek(int inputWeekday);
	void setMonth(int inputMonth);
	void setDay(int inputDay);
	void setYear(int intputYear);
	void printFormatOne();
	void printFormatTwo();
	void printFormatThree();

private:
	int dayOfWeek;
	int month;
	int day;
	int year;
};