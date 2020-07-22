#include "States/State.hpp"

#include "Game.hpp"

#include <TGUI/TGUI.hpp>

State::State(Game& game)
  : m_game(game) 
{
	UI = tgui::Group::create();
	m_game.getGui().add(UI);
}

State::~State()
{
	UI->removeAllWidgets();
	m_game.getGui().remove(UI);
}
