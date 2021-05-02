#include "Board.h"

Board::Board()
{
}

vector<vector<char>> Board::newBoard()
{
	vector<vector<char>> board = {};
	for (int i = 0; i < this->BOARD_WIDTH; i++)
	{
		vector<char> columns = {};
		for (int j = 0; j < this->BOARD_HEIGHT; j++)
		{
			columns.push_back(' ');
		}
		board.push_back(columns);
	}
	return board;
}

void Board::render(vector<vector<char>> board)
{
	std::cout << "  0 1 2" << std::endl;
	std::cout << "  ------" << std::endl;
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		std::cout << i << "| ";
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			std::cout << board[j][i] << " ";
		}
		std::cout << "|\n";
	}
	std::cout << "  ------" << std::endl;


}

bool Board::isBoardFull(vector<vector<char>> board)
{
	int cellTaken = 0;
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			if (board[x][y] == 'X' || board[x][y] == 'O')
			{
				cellTaken++;
			}
		}
	}
	if (cellTaken == BOARD_WIDTH * BOARD_HEIGHT)
	{
		return true;
	}
	return false;
}

tuple<int, int> Board::getMove()
{
	int x = 0, y = 0;
	std::cout << "Enter X coordinate: ";
	std::cin >> x;
	std::cout << "Enter Y coordinate: ";
	std::cin >> y;
	while (true)
	{
		if (isValidMove(this->board, tuple<int, int>(x, y)))
			break;
		else
		{
			std::cout << "Invalid move, try again!\n";
			getMove();
		}
	}
	return tuple<int, int>(x, y);
}

vector<vector<char>> Board::makeMove(vector<vector<char>> board, tuple<int, int> coord, char input)
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

char Board::nextPlayer(int turn)
{
	if (turn % 2 == 0)
		return 'X';
	else
		return 'O';
}

char Board::GetWinner(vector<vector<char>> board)
{
	if (std::get<0>(checkHorizontal(board)))
	{
		return std::get<1>(checkHorizontal(board));
	}
	else if (std::get<0>(checkVertical(board)))
	{
		return std::get<1>(checkVertical(board));
	}
	else if (std::get<0>(checkDiagonals(board)))
	{
		return std::get<1>(checkDiagonals(board));
	}
	return 0;
}

tuple<bool, char> Board::checkHorizontal(vector<vector<char>> board)
{
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
	{
		return tuple<bool, char>(true, 'X');
	}
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
	{
		return tuple<bool, char>(true, 'X');
	}
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
	{
		return tuple<bool, char>(true, 'X');
	}
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
	{
		return tuple<bool, char>(true, 'O');
	}
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
	{
		return tuple<bool, char>(true, 'O');
	}
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
	{
		return tuple<bool, char>(true, 'O');
	}
	return tuple<bool, char>(false, 0);
}

tuple<bool, char> Board::checkVertical(vector<vector<char>> board)
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
	{
		return tuple<bool, char>(true, 'X');
	}
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
	{
		return tuple<bool, char>(true, 'X');
	}
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
	{
		return tuple<bool, char>(true, 'X');
	}
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
	{
		return tuple<bool, char>(true, 'O');
	}
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
	{
		return tuple<bool, char>(true, 'O');
	}
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
	{
		return tuple<bool, char>(true, 'O');
	}
	return tuple<bool, char>(false, 0);
}

tuple<bool, char> Board::checkDiagonals(vector<vector<char>> board)
{
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		return tuple<bool, char>(true, 'X');
	}
	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
	{
		return tuple<bool, char>(true, 'X');
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		return tuple<bool, char>(true, 'O');
	}
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
	{
		return tuple<bool, char>(true, 'O');
	}
	return tuple<bool, char>(false, 0);
}
tuple<int, int> Board::makeRandomMove(vector<vector<char>> board)
{
	int x = 0, y = 0;
	while (true)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (isValidMove(board, tuple<int, int>(x, y)))
		{
			break;
		}
	}
	return tuple<int, int>(x, y);
}

Board::~Board()
{
}
