#include "Application/GameLogic.hpp"

#include "Application/GameSettings.hpp"
#include "Application/UserInterface/UserInterface.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/Controllers/StockItemController.hpp"
#include "Application/GameDataLoader.hpp"

#include <fmt/format.h>
#include <spdlog/spdlog.h>

GameLogic::GameLogic(UserInterface& ui)
	: m_ui(ui)
	, m_playerStatsController(m_playerStats, m_ui)
{
	spdlog::info("GameLogic: created with {} as ui.", static_cast<void*>(&ui));
	
	namespace Components = UIComponentNames;
	auto uiContainer = m_ui.getUIContainer();

	tgui::Button::Ptr stepGameButton = uiContainer->get<tgui::Button>(Components::STEP_BUTTON);
	stepGameButton->onPress([this](){ stepGame(); });

	m_commodities = std::move(loadCommodities());
	
	// Add commodities to UserInterface's trading page
	for (auto& commodity : m_commodities)
	{
		auto stockItemController = m_ui.addStockWidget(commodity);

		m_stockItemControllers.push_back(stockItemController);
	}
}

void GameLogic::stepGame()
{
	for (auto& stockItemController : m_stockItemControllers)
	{
		stockItemController.update();
	}
}

GameLogic::~GameLogic()
{
	spdlog::info("GameLogic: destroyed.");
}
