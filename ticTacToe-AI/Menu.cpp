#include "Menu.h"
void Menu::askNames()
{
	std::cout << "enter player 1 name ";
	std::cin >> this->player1;
	std::cout << "enter player 2 name ";
	std::cin >> this->player2;
	this->board.play();
}

void Menu::showWinner()
{
	int winner = this->board.getWinner();
	if (winner % 2 == 0)
	{
		std::cout << player1 << " won the game!" << std::endl;
	}
	else if(winner % 2 == 1)
	{
		std::cout << player2 << " won the game!" << std::endl;
	}
	else if(winner == -1)
	{
		std::cout << "The game is tied" << std::endl;
	}
}

void Menu::selectAIDifficulty(int mode)
{
	int difficulty = 0;
	std::cout << "Select the difficulty\n1: easy\n2: medium\n3: hard\n";
	std::cin >> difficulty;
	switch(mode)
	{
	case 2:
		this->board.AIPlay(difficulty);
		break;
	case 3:

		break;
	}
}

void Menu::showWinnerAI()
{
	int winner = this->board.getWinner();
	if (winner % 2 == 0)
	{
		std::cout << "player 1 won the game!" << std::endl;
	}
	else if (winner % 2 == 1)
	{
		std::cout << "player 2 won the game!" << std::endl;
	}
	else if (winner == -1)
	{
		std::cout << "The game is tied" << std::endl;
	}
}



void Menu::selectMode()
{
	system("cls");
	int choice = -1;
	std::cout << "Welcome to the game of tic tac toe!\nselect your game mode: " << std::endl;
	std::cout << "1: against another player\n2: against a bot\n3: 2 bots against each other" << std::endl;
	std::cin >> choice;
	
	switch(choice)
	{
	case 1:
		askNames();
		showWinner();
		break;
	case 2:
		selectAIDifficulty(choice);
		showWinnerAI();
		break;
	case 3:
		selectAIDifficulty(choice);
		showWinnerAI();
	default:
		selectMode();
		break;
	}
}