#pragma once

#include "Application/Controllers/StockItemController.hpp"
#include "Application/Market/Commodity.hpp"
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
	UserInterface& m_ui;

	PlayerStats m_playerStats;
	PlayerStatsController m_playerStatsController;
};
