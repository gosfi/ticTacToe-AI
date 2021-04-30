#include "Board.h"

vector<vector<char>> Board::newBoard()
{
	return { {'1', '4', '7'},{'2', '5', '8'}, {'3', '6', '9'} };
}

void Board::render(vector<vector<char>> board)
{
	std::cout << "   0 1 2\n"
		<< "   ------\n"
		<< "0| " << board[0][0] << " " << board[1][0] << " " << board[2][0] << " |\n"
		<< "1| " << board[0][1] << " " << board[1][1] << " " << board[2][1] << " |\n"
		<< "2| " << board[0][2] << " " << board[1][2] << " " << board[2][2] << " |\n"
		<< "   ------\n";
}

bool Board::isBoardFull()
{
	return false;
}

tuple<int, int> Board::getMove()
{
	int x = 0, y = 0;
	std::cout << "Enter X coordinate: ";
	std::cin >> x;
	std::cout << "Enter Y coordinate: ";
	std::cin >> y;
	return tuple<int, int>(x, y);
}

vector<vector<char>> Board::makeMove(vector<vector<char>> board,tuple<int, int> coord, char input)
{

	board[std::get<0>(coord)][std::get<1>(coord)] = input;
	return board;
}

bool Board::isValidMove(vector<vector<char>> board, tuple<int, int> coord)
{
	if (board[std::get<0>(coord)][std::get<1>(coord)] == 'X' || board[std::get<0>(coord)][std::get<1>(coord)] == 'O')
		return false;
	else
		return true;
}
