#include <TGUI/TGUI.hpp>

#include "States/State.hpp"
#include "Game.hpp"

State::State(Game& game, const char* name)
  : m_game(game), m_name(name)
{}
