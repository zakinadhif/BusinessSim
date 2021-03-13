#pragma once

#include "Application/PlayerStats.hpp"
#include "Application/Market/PriceSimulator.hpp"
#include "Application/Controllers/PlayerStatsController.hpp"

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

	UserInterface& m_ui;

	PriceSimulator abacaStock;
	PriceSimulator oilStock;

	PlayerStats m_playerStats;
	PlayerStatsController m_playerStatsController;
};
