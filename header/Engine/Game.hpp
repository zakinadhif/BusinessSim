#pragma once

#include "Engine/GameStateManager.hpp"

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(
	    sf::VideoMode mode,
	    const std::string &title,
	    std::int32_t style = sf::Style::Default,
	    const sf::ContextSettings &settings = sf::ContextSettings()
	);

	void handleEvent(sf::Event event);
	void update(const sf::Time& time);
	void draw() const;

	sf::RenderWindow& getWindow()
	{
		return window;
	};

protected:
	mutable sf::RenderWindow window;

	GameStateManager gameStateManager;
};
