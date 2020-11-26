#include "Application/States/TestState.hpp"

#include "Engine/GameStateManager.hpp"

TestState::TestState(GameStateManager& gameStateManager)
	: GameState(gameStateManager)
{

}

void TestState::handleEvent(sf::Event event)
{
}

void TestState::draw(sf::RenderTarget& target) const 
{
	target.draw(rect);
}
