#ifndef STATE_H
#define STATE_H

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

class Game;

class State
{
public:
  State(Game& game, const char* name);

  virtual void draw(sf::RenderTarget& renderTarget) = 0;
  virtual void update(sf::Time elapsed) {}
  virtual void fixedUpdate(sf::Time elapsed) {}
  virtual void onOpen() {}

  virtual void handleEvent(sf::Event event) {}
  virtual void handleInput() {}

  virtual ~State() = default;
protected:
  Game& m_game;
  std::string m_name;
};

#endif
