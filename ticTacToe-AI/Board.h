#include <iostream>
#include <time.h>
#include <vector>
#include <tuple>
using std::vector;
using std::tuple;

#pragma once
class Board
{
private:
	const int BOARD_WIDTH = 3;
	const int BOARD_HEIGHT = 3;
public:
	Board();
	vector<vector<char>> board;
	tuple<int, int> coord;
	vector<vector<char>> newBoard();
	void render(vector<vector<char>> board);
	bool isBoardFull(vector<vector<char>> board);
	tuple<int, int> getMove();
	vector<vector<char>> makeMove(vector<vector<char>> board, tuple<int, int> coord, char input);
	bool isValidMove(vector<vector<char>> board, tuple<int, int> coord);
	char nextPlayer(int turn);
	char GetWinner(vector<vector<char>> board);
	tuple<bool, char> checkHorizontal(vector<vector<char>> board);
	tuple<bool, char> checkVertical(vector<vector<char>> board);
	tuple<bool, char> checkDiagonals(vector<vector<char>> board);
	tuple<int, int> makeRandomMove(vector<vector<char>> board);
	~Board();
};

