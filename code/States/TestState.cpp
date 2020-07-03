#include "States/TestState.hpp"

TestState::TestState(Game& game, const char* name) 
    : State(game, name)
{}

void TestState::draw(sf::RenderTarget& renderTarget) {}

void TestState::update(sf::Time elapsed) {}

void TestState::fixedUpdate(sf::Time elapsed) {}

void TestState::onOpen() {}

void TestState::handleEvent(sf::Event event) {}

void TestState::handleInput() {}