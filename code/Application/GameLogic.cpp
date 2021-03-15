#include "Application/GameLogic.hpp"

#include "Application/GameSettings.hpp"
#include "Application/UserInterface/UserInterface.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"

#include <fmt/format.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>

GameLogic::GameLogic(UserInterface& ui)
	: m_ui(ui)
	, m_playerStatsController(m_playerStats, m_ui)
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

	oilStock.setPrice(20.0f);
	oilStock.setDrift(0.0001f);
	oilStock.setVolatility(0.02f);
}

void GameLogic::initUILogics()
{
	namespace Components = UIComponentNames;

	auto uiContainer = m_ui.getUIContainer();

	tgui::Button::Ptr stepGameButton = uiContainer->get<tgui::Button>(Components::STEP_BUTTON);
	stepGameButton->onPress([this](){ stepGame(); });

	m_ui.addStockWidget(abacaStock, "Abaca Inc");
	m_ui.addStockWidget(oilStock, "Oil");
}

void GameLogic::stepGame()
{
	abacaStock.step();
	oilStock.step();
	m_ui.updateStockWidgetList();
}

GameLogic::~GameLogic()
{
	spdlog::info("GameLogic: destroyed.");
}
