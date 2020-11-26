#pragma once

#include "Application/UserInterface.hpp"

#include "Engine/GameState.hpp"

#include <TGUI/TGUI.hpp>

class GameStateManager;

class MainState : public GameState
{
public:
	MainState(GameStateManager& gameStateManager, tgui::Gui& gui);

	void handleEvent(sf::Event event) override;
	void update(const sf::Time& time) override;
	void draw(sf::RenderTarget& target) const override;

private:
	tgui::Gui& gui;
	UserInterface userInterface;
};
