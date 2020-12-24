#include "Application/GameLogic.hpp"

#include "Application/Stock/StockSettings.hpp"
#include "Application/UserInterface/UserInterface.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"

#include <fmt/format.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>

GameLogic::GameLogic(UserInterface& ui)
	: ui(ui), abacaStock(StockSettings::STOCK_TRADING_LENGTH)
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
	// Abaca Stock
	abacaStock.setPrice(12.99f);
	abacaStock.setDrift(0.5f);
	abacaStock.setVolatility(0.2f);
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
}

void GameLogic::stepGame()
{
	++gameStepCount;
	spdlog::info("GameLogic: gameStepCount: {}", gameStepCount);

	abacaStock.step();
	spdlog::info("GameLogic: [OnlyFun] abaca stock price is at {} E coins", abacaStock.getPrice());

	auto uiContainer = ui.getUIContainer();
	tgui::Group::Ptr abacaStockWidget = uiContainer->get<tgui::Group>(UIComponentNames::ABACA_STOCK);
	
	tgui::Label::Ptr abacaPriceLabel = abacaStockWidget->get<tgui::Label>(UIComponentNames::STOCK_LAST_PRICE_LABEL);
	abacaPriceLabel->setText(fmt::format("{} E", abacaStock.getPrice()));
}

GameLogic::~GameLogic()
{
	spdlog::info("GameLogic: destroyed.");
	playerStats.removeListener(playerStatsUICallbacksID);
}
