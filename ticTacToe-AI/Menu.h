#include <iostream>
#include <string>
#include "Games.h"
using std::string;
#pragma once

class Menu
{
private:
	Games games = Games();
	string gameNames[1] = { "Tic tac toe" };
public:
	void SelectGame();
};

