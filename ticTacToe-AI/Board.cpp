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

int Board::askCell()
{
	std::cout << "Enter a number: ";
	std::cin >> this->cell;
	if (this->board[cell - 1] != this->X && this->board[cell - 1] != this->O)
	{
		return cell - 1;
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
	else if (player == 1)
	{
		this->board[cell] = this->O;
	}
}

void Board::putCharacterAI(int cell)
{
	this->board[cell] = this->O;
}

void Board::setWinner(int winner)
{
	this->player = winner;
}

int Board::getWinner()
{
	return this->player;
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
	do
	{
		system("cls");
		drawBoard();
		this->player = checkPlayer(this->player);
		this->cell = askCell();
		putCharacter(this->cell);
		this->hasWon = checkWin();
		this->isTie = checkIfBoardFull();
		this->player += 1;
	} while (!hasWon && !isTie);

	if (hasWon)
	{
		system("cls");
		drawBoard();
		setWinner(player);
	}
	else if (isTie)
	{
		system("cls");
		drawBoard();
		setWinner(-1);
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

void Board::AIPlay(int difficulty = 1)
{
	srand(time(NULL));
	do
	{
		system("cls");
		drawBoard();
		this->player = checkPlayer(this->player);
		this->cell = askCell();
		putCharacter(this->cell);
		this->player++;

		switch (difficulty)
		{
		case 1:
			this->cell = randomAi();
			putCharacterAI(this->cell);
			this->player++;
			break;
		}
		this->hasWon = checkWin();
		this->isTie = checkIfBoardFull();
	} while (!hasWon && !isTie);
	if (hasWon)
	{
		system("cls");
		drawBoard();
		setWinner(player);
	}
	else if (isTie)
	{
		system("cls");
		drawBoard();
		setWinner(-1);
	}
}

void Board::TwoAI(int difficulty)
{
	srand(time(NULL));
	do 
	{
		for (int i = 0; i < 2; i++)
		{
			system("cls");
			drawBoard();
			this->player = checkPlayer(this->player);
			this->cell = checkDifficulty(difficulty);
		}
	} while (!this->hasWon && !isTie);
	if (hasWon)
	{
		system("cls");
		drawBoard();
		setWinner(player);
	}
	else if (isTie)
	{
		system("cls");
		drawBoard();
		setWinner(1);
	}
}

int Board::randomAi()
{
	int cell = rand() % 8;
	if (this->board[cell] == this->X || this->board[cell] == this->O)
	{
		randomAi();
	}
	else
	{
		return cell;
	}
}

int Board::winningMovesAi(int player)
{
	return 0;
}

int Board::checkDifficulty(int difficulty)
{
	int cell = 0;
	switch(difficulty)
	{
	case 1:
		cell = randomAi();
		return cell;
		break;
	case 2:
		cell = winningMovesAi(this->player);
		return cell;
		break;
	}
}

