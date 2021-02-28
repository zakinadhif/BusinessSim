#include "Application/States/MainState.hpp"

#include "Application/GameLogic.hpp"
#include "Application/UserInterface/UserInterface.hpp"
#include "Engine/GameStateManager.hpp"

#include <TGUI/Widgets/Group.hpp>

MainState::MainState(GameStateManager& gameStateManager, tgui::Gui& gui)
	: GameState{gameStateManager} 
	, gui{gui}
	, container{tgui::Group::create()}
	, userInterface{container}
	, gameLogic{userInterface}
{
	gui.add(container, "mainUi");
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
}
