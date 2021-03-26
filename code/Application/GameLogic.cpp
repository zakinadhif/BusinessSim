#include "Application/GameLogic.hpp"

#include "Application/GameSettings.hpp"
#include "Application/UserInterface/UserInterface.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/Controllers/StockItemController.hpp"

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
}

void GameLogic::stepGame()
{
}

GameLogic::~GameLogic()
{
	spdlog::info("GameLogic: destroyed.");
}
