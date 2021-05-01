#include "Menu.h"

void Menu::SelectGame()
{
	int choice = 0;
	std::cout << "select game\n1: " << this->gameNames[0] << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		this->games.ticTacToe();
		break;
	}
}
