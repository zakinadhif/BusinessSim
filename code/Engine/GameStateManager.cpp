#pragma once

#include <memory>

class GameState;

class GameStateManager : public sf::Drawable
{
public:
	GameStateManager();

	void push(std::unique_ptr<GameState> state);
	std::unique_ptr<GameState> pop();
	GameState& peek();
	
	const GameState& peek() const;

	void update(const sf::Time& elapsed);
	void draw(s)

private:
};
