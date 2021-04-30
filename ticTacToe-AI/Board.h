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
public:
	vector<vector<char>> board;
	tuple<int, int> coord;
	vector<vector<char>> newBoard();
	void render(vector<vector<char>> board);
	bool isBoardFull();
	tuple<int, int> getMove();
	vector<vector<char>> makeMove(vector<vector<char>> board, tuple<int, int> coord, char input);
	bool isValidMove(vector<vector<char>> board,tuple<int, int> coord);
};

