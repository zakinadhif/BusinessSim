#pragma once

#include "States/State.hpp"

class TestState : public State
{
  TestState(Game& game, const char* name);

  void draw(sf::RenderTarget& renderTarget) {}
  void update(sf::Time elapsed) {}
  void fixedUpdate(sf::Time elapsed) {}
  void onOpen() {}

  void handleEvent(sf::Event event) {}
  void handleInput() {}
};