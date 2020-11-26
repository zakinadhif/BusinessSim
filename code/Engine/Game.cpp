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

void Game::handleEvent(sf::Event event)
{
	gameStateManager.handleEvent(event);
}

void Game::update(const sf::Time &time)
{
	gameStateManager.update(time);
}

void Game::draw() const
{
	window.clear();
	gameStateManager.draw(window);
	window.display();
}
