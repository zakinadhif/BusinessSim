#include "Application/States/MainState.hpp"

#include "Application/UserInterface.hpp"
#include "Engine/GameStateManager.hpp"

#include <TGUI/Widgets/Group.hpp>

MainState::MainState(GameStateManager& gameStateManager, tgui::Gui& gui)
	: GameState(gameStateManager), gui(gui)
{
	auto uiContainer = tgui::Group::create();
	gui.add(uiContainer, "mainUi");

	userInterface = new UserInterface(uiContainer);
}

void MainState::handleEvent(sf::Event event)
{
}

void MainState::update(const sf::Time &time)
{

}

void MainState::draw(sf::RenderTarget &target) const
{

}

MainState::~MainState()
{
	delete userInterface;
}
