#include "Engine/GameStateManager.hpp"
#include "Engine/GameState.hpp"

#include <memory>

GameStateManager::GameStateManager()
{

}

void GameStateManager::push(std::unique_ptr<GameState> state)
{
	states.push(std::move(state));
}

GameState& GameStateManager::peek()
{
	return *(states.top().get());
}

const GameState& GameStateManager::peek() const
{
	return *(states.top().get());
}

void GameStateManager::pop()
{
	states.pop();
}

void GameStateManager::handleEvent(sf::Event event)
{
	if (!states.empty())
		peek().handleEvent(event);
}

void GameStateManager::update(const sf::Time& time)
{
	if (!states.empty())
		peek().update(time);
}

void GameStateManager::draw(sf::RenderTarget &target) const
{
	if (!states.empty())
		peek().draw(target);
}
