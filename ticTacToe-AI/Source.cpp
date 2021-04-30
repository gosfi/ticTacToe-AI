#include <iostream>
#include "Menu.h"
#include "Board.h"

int main()
{
	Menu menu = Menu();
	Board board = Board();
	board.board = board.newBoard();
	board.render(board.board);
	board.coord = board.getMove();
	std::cout << std::get<0>(board.coord) << ", " << std::get<1>(board.coord) << std::endl;
	return 0;
}