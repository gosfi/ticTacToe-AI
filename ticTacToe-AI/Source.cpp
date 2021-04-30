#include <iostream>
#include "Menu.h"
#include "Board.h"

int main()
{
	Menu menu = Menu();
	Board board = Board();
	board.board = board.newBoard();
	board.render(board.board);
	while (true)
	{
		board.coord = board.getMove();
		if (board.isValidMove(board.board, board.coord))
		{
			break;
		}
		else
			std::cout << "Invalid move!";
	}
	board.board = board.makeMove(board.board, board.coord, 'X');
	board.render(board.board);
	return 0;
}