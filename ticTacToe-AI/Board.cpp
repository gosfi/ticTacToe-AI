#include "Board.h"

void Board::drawBoard()
{
	std::cout << "      |      |      \n"
		<< "  " << this->board[0] << "   |  " << this->board[1] << "   |   " << this->board[2] << "   \n"
		<< "      |      |      \n"
		<< "--------------------\n"
		<< "      |      |      \n"
		<< "  " << this->board[3] << "   |  " << this->board[4] << "   |   " << this->board[5] << "   \n"
		<< "      |      |      \n"
		<< "--------------------\n"
		<< "      |      |      \n"
		<< "  " << this->board[6] << "   |  " << this->board[7] << "   |   " << this->board[8] << "   \n"
		<< "      |      |      \n";
}

int Board::checkPlayer(int player)
{
	if (player % 2 == 0)
		return 0;
	else
		return 1;
}

void Board::askCell()
{
	std::cout << "Enter a number: ";
	std::cin >> this->cell;
	if (this->board[cell - 1] != this->X && this->board[cell - 1] != this->O)
	{
		putCharacter(cell - 1);
	}
	else
	{
		askCell();
	}
}

void Board::putCharacter(int cell)
{
	if (player == 0)
	{
		this->board[cell] = this->X;
	}
	else if(player == 1)
	{
		this->board[cell] = this->O;
	}
}

bool Board::checkWin()
{
	if (this->board[0] == this->board[1] && this->board[1] == this->board[2])
	{
		return true;
	}
	else if (this->board[3] == this->board[4] && this->board[4] == this->board[5])
	{
		return true;
	}
	else if (this->board[6] == this->board[7] && this->board[7] == this->board[8])
	{
		return true;
	}
	else if (this->board[0] == this->board[3] && this->board[3] == this->board[6])
	{
		return true;
	}
	else if (this->board[1] == this->board[4] && this->board[4] == this->board[7])
	{
		return true;
	}
	else if (this->board[2] == this->board[5] && this->board[5] == this->board[8])
	{
		return true;
	}
	else if (this->board[0] == this->board[4] && this->board[4] == this->board[8])
	{
		return true;
	}
	else if (this->board[2] == this->board[4] && this->board[4] == this->board[6])
	{
		return true;
	}
	else
	{
		return false;
	}
}



void Board::play()
{
	while (!hasWon && !isTie)
	{
		system("cls");
		drawBoard();
		this->player = checkPlayer(this->player);
		askCell();
		this->hasWon = checkWin();
		this->isTie = checkIfBoardFull();
		this->player += 1;
	}
	if (hasWon)
	{
		system("cls");
		drawBoard();
		std::cout << "player " << this->player << " has won!" << std::endl;
	}
	else if (isTie)
	{
		system("cls");
		drawBoard();
		std::cout << "The game is tied!" << std::endl;
	}
}

bool Board::checkIfBoardFull()
{
	int count = 0;
	for (int i = 0; i < sizeof(this->board); i++)
	{
		if (this->board[i] == this->X || this->board[i] == this->O)
		{
			count++;
		}
	}
	if (count >= sizeof(this->board))
	{
		return true;
	}
	else
	{
		return false;
	}
}

