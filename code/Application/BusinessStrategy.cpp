#include "Application/BusinessStrategy.hpp"

#include "Application/States/MainState.hpp"

BusinessStrategy::BusinessStrategy()
	: Game(sf::VideoMode(800, 800), "TestGame")
	, gui(window)
{
	gameStateManager.push(std::make_unique<MainState>(gameStateManager,gui));
}

void BusinessStrategy::handleEvent(sf::Event event)
{
	gui.handleEvent(event);
	gameStateManager.handleEvent(event);
}

void BusinessStrategy::update(const sf::Time& time)
{
	gameStateManager.update(time);
}

void BusinessStrategy::draw() const
{
	window.clear();
	gui.draw();
	gameStateManager.draw(window);
	window.display();
}

