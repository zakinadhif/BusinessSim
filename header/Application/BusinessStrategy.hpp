#pragma once

#include "Engine/Game.hpp"

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class BusinessStrategy : public Game
{
public:
	BusinessStrategy();

	void handleEvent(sf::Event event) override;
	void update(const sf::Time& time) override;
	void draw() const override;

private:
	mutable tgui::Gui gui;
	GameStateManager gameStateManager;
};
