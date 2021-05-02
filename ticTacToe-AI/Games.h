#include "Board.h"
#include <iostream>
#pragma once
class Games
{
private:
	Board board = Board();
public:
	void ticTacToe();
	void ticTacToeAI(int difficulty);
};

