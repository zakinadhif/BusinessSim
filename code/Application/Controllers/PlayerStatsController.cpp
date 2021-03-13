#include "Application/Controllers/PlayerStatsController.hpp"
#include "Application/UserInterface/UserInterface.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/PlayerStats.hpp"

#include <fmt/format.h>

PlayerStatsController::PlayerStatsController(PlayerStats& playerStats, UserInterface& userInterface)
	: m_playerStats{ playerStats }
{
	auto uiContainer = userInterface.getUIContainer();

	namespace Components = UIComponentNames;

	m_moneyLabel = uiContainer->get<tgui::Label>(Components::MONEY_LABEL);
	m_ticketLabel = uiContainer->get<tgui::Label>(Components::TICKET_LABEL);
}

PlayerStats& PlayerStatsController::get()
{
	return m_playerStats;
}

const PlayerStats& PlayerStatsController::get() const
{
	return m_playerStats;
}

void PlayerStatsController::updateView()
{
	m_moneyLabel->setText(fmt::to_string(m_playerStats.money));	
	m_moneyLabel->setText(fmt::to_string(m_playerStats.ticket));
}
