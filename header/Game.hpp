#ifndef GAME_H
#define GAME_H

#include "States/State.hpp"

#include <SFML/Graphics.hpp>
#include <stack>
#include <memory>

class State;

class Game
{
public:
  Game();

  template<typename T>
  void run();

  void pushState(std::unique_ptr<State> state);
  void popState();
  void changeState(std::unique_ptr<State> state);
  State* peekState();

  template<typename T, typename... Args>
  void pushState(Args&&... args);

  void handleEvent();
  void handleInput();

  sf::RenderWindow& getRenderWindow();
private:
  void routine();

  sf::RenderWindow m_window;
  std::stack<std::unique_ptr<State>> m_states;
};

template<typename T>
void Game::run()
{
  pushState(std::make_unique<T>(*this));
  routine();
}

template<typename T, typename... Args>
void Game::pushState(Args&&... args)
{
  pushState(std::make_unique<T>(std::forward<Args>(args)...));
}

#endif
