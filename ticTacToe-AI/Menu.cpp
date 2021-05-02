#include "Menu.h"

void Menu::SelectGame()
{
	int choice = 0;
	std::cout << "select game\n1: " << this->gameNames[0] << std::endl;
	std::cout << "2: " << this->gameNames[1] << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		this->games.ticTacToe();
		break;
	case 2:
		SelectAIDifficulty();
		break;
	}
}

void Menu::SelectAIDifficulty()
{
	int choice = 0;
	std::cout << "Enter a difficulty\n1: easy\n2: medium\n3: hard\n";
	std::cin >> choice;
	this->games.ticTacToeAI(choice);
}
