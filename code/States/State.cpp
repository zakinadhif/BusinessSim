#include <TGUI/TGUI.hpp>

#include "States/State.hpp"
#include "Game.hpp"

State::State(Game& game)
  : m_game(game), m_gui(game.getGui()) 
{
}
