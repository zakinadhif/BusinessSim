#pragma once

#include "Application/UserInterface/UserInterface.hpp"
#include "Application/PlayerStats.hpp"

#include "Application/GameLogic.hpp"

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

	~MainState();	

private:
	tgui::Gui& gui;
	tgui::Group::Ptr container;
	UserInterface userInterface;
	GameLogic gameLogic;
};
