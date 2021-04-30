#include <iostream>
#include <time.h>

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
	int askCell();
	void putCharacter(int cell);
	void putCharacterAI(int cell);
	void setWinner(int winner);
	int getWinner();
	bool checkWin();
	void play();
	bool checkIfBoardFull();
	void AIPlay(int difficulty);
	void TwoAI(int difficulty);
	int randomAi();
	int winningMovesAi(int player);
	int checkDifficulty(int difficulty);
};

