#ifndef STATE_H
#define STATE_H

#include "Game.hpp"

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class Game;

class State
{
public:
  State(Game& game);

  virtual void draw(sf::RenderTarget& renderTarget) = 0;
  virtual void update(sf::Time elapsed) {}
  virtual void fixedUpdate(sf::Time elapsed) {}
  virtual void lateUpdate(sf::Time elapsed) {}
	virtual void onOpen() {}

  virtual void handleEvent(sf::Event event) {}
  virtual void handleInput() {}

  virtual ~State() = default;
protected:
  Game& m_game;
	tgui::Gui& m_gui;
};

#endif
