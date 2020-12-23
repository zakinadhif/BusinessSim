#pragma once

#include "Application/PlayerStats.hpp"
#include "Application/Stock/StockSimulator.hpp"

#include <TGUI/TGUI.hpp>

class UserInterface;

class GameLogic
{
public:
	GameLogic(UserInterface& userInterface);

	void stepGame();

	~GameLogic();

private:
	void init();
	void initUILogics();
	void initStocks();

	std::size_t gameStepCount = 0;

	PlayerStats playerStats;
	UserInterface& ui;

	StockSimulator abacaStock;

	std::size_t playerStatsUICallbacksID = 0;
};
