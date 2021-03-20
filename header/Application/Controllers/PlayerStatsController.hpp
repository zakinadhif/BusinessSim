#pragma once

#include "Application/PlayerStats.hpp"

#include <TGUI/Widgets/Label.hpp>

class UserInterface;

class PlayerStatsController
{
public:
	PlayerStatsController(PlayerStats& playerStats, UserInterface& userInterface);

	void setHealth(float health) { m_playerStats.health = health; }
	float getHealth() const { return m_playerStats.health; }

	void setMoney(float money) { m_playerStats.money = money; }
	float getMoney() const { return m_playerStats.money; }

	void setHappiness(float happiness) { m_playerStats.happiness = happiness; }
	float getHappiness() const { return m_playerStats.happiness; }

	void setTicket(int ticket) { m_playerStats.ticket = ticket; }
	int getTicket() const { return m_playerStats.ticket; }
	
	void updateView();

private:
	PlayerStats& m_playerStats;

	tgui::Label::Ptr m_moneyLabel, m_ticketLabel;
};
