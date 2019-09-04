/*
Steve Gonzalez
CIS 2541-003
05/03/2018
HW5 Q1
*/

#include <iomanip>
#include <iostream>
#include <string>

struct BoardGame
{
	std::string name;
	int minPlayers;
	int maxPlayers;
	int minAge;
	double playTime;
	int rating;
};

// Function Prototypes
void getInfo(BoardGame * ptr);
void display(const BoardGame  list[], int size);

int main()
{
	const int ARRAY_SIZE = 3;
	// Declare an array of BoardGame structures
	BoardGame gameList[ARRAY_SIZE];

	// Prompt the user to enter data for each element of the array
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		std::cout << "Enter the following information about a board game." << std::endl;
		getInfo(&gameList[i]);
	}

	// Display the data in the arragy
	display(gameList, ARRAY_SIZE);

	system("PAUSE");
	return 0;
}

void getInfo(BoardGame * ptr)
{
	// Prompt user to enter data for each field
	std::cout << "Name of the game: ";
	std::getline(std::cin, ptr->name);
	std::cout << "Minimum number of players: ";
	std::cin >> ptr->minPlayers;
	std::cout << "Maximum number of players: ";
	std::cin >> ptr->maxPlayers;
	std::cout << "Minimum recommended age ";
	std::cin >> ptr->minAge;
	std::cout << "Estimated time to play (in minutes): ";
	std::cin >> ptr->playTime;
	std::cout << "Game rating (1-10): ";
	std::cin >> ptr->rating;
	std::cin.ignore();
}

void display(const BoardGame list[], int size)
{
	std::cout << std::setw(79) << std::setfill('-') << "-" << std::endl;
	std::cout << "Here is a list of the board games you stored." << std::endl;
	std::cout << std::left << std::setw(16) << std::setfill(' ') << "Name ";
	std::cout << std::left << std::setw(12) << std::setfill(' ') << "Min Players ";
	std::cout << std::left << std::setw(12) << std::setfill(' ') << "Max Players ";
	std::cout << std::left << std::setw(10) << std::setfill(' ') << "Min Age ";
	std::cout << std::left << std::setw(14) << std::setfill(' ') << "Est Play Time ";
	std::cout << std::left << std::setw(10) << std::setfill(' ') << "Rating " << std::endl;

	for (int i = 0; i < size; ++i)
	{
		std::cout << std::left << std::setw(16) << std::setfill(' ') << list[i].name << " ";
		std::cout << std::left << std::setw(12) << std::setfill(' ') << list[i].minPlayers << " ";
		std::cout << std::left << std::setw(12) << std::setfill(' ') << list[i].maxPlayers << " ";
		std::cout << std::left << std::setw(10) << std::setfill(' ') << list[i].minAge << " ";
		std::cout << std::left << std::setw(14) << std::setfill(' ') << list[i].playTime << " ";
		std::cout << std::left << std::setw(10) << std::setfill(' ') << list[i].rating << std::endl;
	}
	std::cout << std::setw(79) << std::setfill('-') << "-" << std::endl;
}