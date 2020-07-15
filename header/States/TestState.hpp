#ifndef TESTSTATE_H
#define TESTSTATE_H

#include "States/State.hpp"
#include "Game.hpp"

#include <SFML/Graphics.hpp>

class TestState : public State
{
public:
  TestState(Game& game);

  void draw(sf::RenderTarget& renderTarget);
  void update(sf::Time elapsed);
  void fixedUpdate(sf::Time elapsed);
  void onOpen();

  void handleEvent(sf::Event event);
  void handleInput();

	~TestState();
private:
	tgui::Group::Ptr thisGroup;
};

#endif
