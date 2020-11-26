#pragma once

#include "Engine/GameState.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <stack>

class GameStateManager
{
public:
	GameStateManager();
	
	void push(std::unique_ptr<GameState> state);
	void pop();
	GameState& peek();
	
	const GameState& peek() const;

	void handleEvent(sf::Event event);
	void update(const sf::Time& elapsed);
	void draw(sf::RenderTarget& target) const;

private:
	std::stack<std::unique_ptr<GameState>> states;
};
