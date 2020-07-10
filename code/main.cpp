#include "Game.hpp"
#include "States/TestState.hpp"

#include <SFML/Graphics.hpp>

int main() {
  Game game;
  game.run<TestState>();

  return 0;
}
