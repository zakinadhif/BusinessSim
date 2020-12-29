#pragma once

#include "Application/PlayerStats.hpp"
#include "Application/Price/PriceSimulator.hpp"

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

	PriceSimulator abacaStock;
	PriceSimulator oilStock;

	std::size_t playerStatsUICallbacksID = 0;
};
