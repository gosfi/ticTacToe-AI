#include <iostream>
#include <string>
#include "Board.h"
using std::string;
#pragma once

class Menu
{
private:
	Board board = Board();
	string player1, player2;
public:
	
	void selectMode();
	void askNames();
	void showWinner();
	void selectAIDifficulty(int mode);
	void showWinnerAI();
};

