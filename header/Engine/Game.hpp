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

	virtual void handleEvent(sf::Event event) = 0;
	virtual void update(const sf::Time& time) = 0;
	virtual void draw() const = 0;

	sf::RenderWindow& getWindow()
	{
		return window;
	};

protected:
	mutable sf::RenderWindow window;
};
