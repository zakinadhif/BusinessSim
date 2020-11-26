#include "Engine/Game.hpp"

#include "Engine/GameState.hpp"

Game::Game(
    sf::VideoMode mode,
    const std::string &title,
    std::int32_t style,
    const sf::ContextSettings &settings
)
	: window(mode, title, style, settings)
{
}
