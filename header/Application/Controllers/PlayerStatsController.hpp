#pragma once

#include <TGUI/Widgets/Label.hpp>

struct PlayerStats;
class UserInterface;

class PlayerStatsController
{
public:
	PlayerStatsController(PlayerStats& playerStats, UserInterface& userInterface);

	PlayerStats& get();
	const PlayerStats& get() const;

	void updateView();
private:
	PlayerStats& m_playerStats;

	tgui::Label::Ptr m_moneyLabel, m_ticketLabel;
};
