#include <iostream>
#pragma once
class Board
{
private:
	int player = 0;
	int cell = -1;
	bool hasWon = false, isTie = false;
	char board[9] = { '1','2','3','4','5','6','7','8','9' };
	const char X = 'X';
	const char O = 'O';
	char answer = ' ';
public:
	void drawBoard();
	int checkPlayer(int player);
	void askCell();
	void putCharacter(int cell);
	bool checkWin();
	void play();
	bool checkIfBoardFull();
};

