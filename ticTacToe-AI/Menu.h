#include <iostream>
#include <string>
#include "Games.h"
using std::string;
#pragma once

class Menu
{
private:
	Games games = Games();
	string gameNames[2] = { "Tic tac toe", "Tic tac toe against an AI" };
public:
	void SelectGame();
	void SelectAIDifficulty();
};

