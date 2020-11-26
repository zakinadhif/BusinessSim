#pragma once

#include <SFML/Graphics.hpp>

class GameStateManager;

class GameState
{
public:
	GameState(GameStateManager& gameStateManager);	

	virtual void handleEvent([[maybe_unused]] sf::Event event);
	virtual void update([[maybe_unused]] const sf::Time& time);
	virtual void draw(sf::RenderTarget& target) const = 0;

	virtual ~GameState() = default;

protected:
	GameStateManager& gameStateManager;
};
