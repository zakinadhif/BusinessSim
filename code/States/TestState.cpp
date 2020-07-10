#include "States/TestState.hpp"

#include "Game.hpp"

TestState::TestState(Game& game) 
    : State(game)
{}

void TestState::draw(sf::RenderTarget& renderTarget) {}

void TestState::update(sf::Time elapsed) {}

void TestState::fixedUpdate(sf::Time elapsed) {}

void TestState::onOpen() {}

void TestState::handleEvent(sf::Event event) {}

void TestState::handleInput() {}
