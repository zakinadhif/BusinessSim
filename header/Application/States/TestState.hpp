#pragma once

#include "Engine/GameState.hpp"

class GameStateManager;

class TestState : public GameState
{
public:
	TestState(GameStateManager& gameStateManager);

	void handleEvent(sf::Event event) override;
	void draw(sf::RenderTarget& target) const override;

private:
	sf::RectangleShape rect = sf::RectangleShape({100, 100});
};
