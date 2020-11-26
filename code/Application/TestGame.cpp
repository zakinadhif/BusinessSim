#include "Application/TestGame.hpp"

TestGame::TestGame()
	: Game(sf::VideoMode(800, 800), "TestGame")
{
	gameStateManager.push(std::make_unique<TestState>(gameStateManager));
}
