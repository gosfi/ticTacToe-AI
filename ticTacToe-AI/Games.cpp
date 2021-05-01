#include "Games.h"

void Games::ticTacToe()
{
	this->board.board = this->board.newBoard();
	int nbTurn = 0;
	char toPlay = ' ';
	while (true)
	{
		system("cls");
		this->board.render(this->board.board);
		toPlay = this->board.nextPlayer(nbTurn);
		this->board.coord = this->board.getMove();
		this->board.board = this->board.makeMove(this->board.board, this->board.coord, toPlay);
		if (this->board.GetWinner(this->board.board) == 'X' || this->board.GetWinner(this->board.board) == 'O')
		{
			char winner = this->board.GetWinner(this->board.board);
			this->board.render(this->board.board);
			std::cout << winner << " has won!";
			break;
		}
		else if (this->board.isBoardFull(this->board.board))
		{
			this->board.render(this->board.board);
			std::cout << "It's a tie!" << std::endl;
			break;
		}
		nbTurn++;
	}
}
