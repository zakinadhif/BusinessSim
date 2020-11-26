#include "Engine/Engine.hpp"

#include "Engine/Game.hpp"

#include <cassert>

Engine::Engine()
{
}

void Engine::routine()
{
	assert(game);

	sf::RenderWindow& window = game->getWindow();

	sf::Clock timer;
	sf::Time elapsed = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			game->handleEvent(event);
		}

		game->update(elapsed);
		
		game->draw();

		elapsed = timer.restart();
	}
}

Engine::~Engine()
{
	if (game) delete game;
}
