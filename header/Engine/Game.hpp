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

private:
	mutable sf::RenderWindow window;

protected:
	GameStateManager gameStateManager;
};
