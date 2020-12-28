#include "Application/GameLogic.hpp"

#include "Application/GameSettings.hpp"
#include "Application/UserInterface/UserInterface.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"

#include <fmt/format.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>

GameLogic::GameLogic(UserInterface& ui)
	: ui(ui) 
{
	spdlog::info("GameLogic: created with {} as ui.", static_cast<void*>(&ui));
	init();
}

void GameLogic::init()
{
	initUILogics();
	initStocks();
}

void GameLogic::initStocks()
{
	abacaStock.setPrice(12.0f);
	abacaStock.setDrift(0.01f);
	abacaStock.setVolatility(0.02f);
}

void GameLogic::initUILogics()
{
	using namespace UIComponentNames;

	playerStatsUICallbacksID = playerStats.addListener(
		[this](const PlayerStats& playerStats)
		{
			auto uiContainer = ui.getUIContainer();
			
			tgui::Label::Ptr moneyDisplay = uiContainer->get<tgui::Label>(MONEY_LABEL);
			moneyDisplay->setText(fmt::to_string(playerStats.getMoney()));
			
			tgui::Label::Ptr ticketDisplay = uiContainer->get<tgui::Label>(TICKET_LABEL);
			ticketDisplay->setText(fmt::to_string(playerStats.getTicket()));
		}
	);

	auto uiContainer = ui.getUIContainer();
	
	tgui::Button::Ptr stepGameButton = uiContainer->get<tgui::Button>(STEP_BUTTON);
	stepGameButton->connect("pressed", [this](){ stepGame(); });

	spdlog::info("GameLogic: initialization complete.");

	ui.addStockWidget(abacaStock, "abaca inc");	
}

void GameLogic::stepGame()
{
	++gameStepCount;
	spdlog::info("GameLogic: gameStepCount: {}", gameStepCount);

	abacaStock.step();
	ui.updateStockWidgetList();
}

GameLogic::~GameLogic()
{
	spdlog::info("GameLogic: destroyed.");
	playerStats.removeListener(playerStatsUICallbacksID);
}
