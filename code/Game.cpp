#include "Game.hpp"

#include "States/State.hpp"

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>


Game::Game()
{
  sf::ContextSettings contextSettings;
  contextSettings.antialiasingLevel = 2;
  m_window.create(
    sf::VideoMode(1366u,768u)
    , "Delivere"
    , sf::Style::Fullscreen
    , contextSettings
  );

  m_window.setFramerateLimit(60);

	if (!defaultFont.loadFromFile("assets/Arial.ttf"))
	{
		std::cout << "Fail to load default font" << std::endl;
	}

	m_gui.setTarget(m_window);
	m_gui.setFont(defaultFont);
}

void Game::routine()
{
  constexpr unsigned int ticksPerSecond = 30;
  const sf::Time timePerUpdate = sf::seconds(1.0f / float(ticksPerSecond));
  unsigned int ticks = 0;

  sf::Clock timer;
  sf::Time lag = sf::Time::Zero;

  while(m_window.isOpen() && !m_states.empty())
  {
    State& activeState = *peekState();

    // Get elapsed time and restart the timer
    sf::Time elapsed = timer.restart();
    lag += elapsed;

    handleInput();
		handleEvent();

		if (lag >= timePerUpdate)
		{
			ticks++;
			lag -= timePerUpdate;
			peekState()->fixedUpdate(elapsed);
		}
    
		activeState.update(elapsed);
		activeState.lateUpdate(elapsed);

    m_window.clear();
    activeState.draw(m_window);
		m_gui.draw();
    m_window.display();
  }
}

void Game::pushState(std::unique_ptr<State> state)
{
  m_states.push(std::move(state));
  peekState()->onOpen();
}

void Game::popState()
{
  m_states.pop();
}

void Game::changeState(std::unique_ptr<State> state)
{
  popState();
  pushState(std::move(state));
}

State* Game::peekState()
{
  return m_states.top().get();
}

void Game::handleEvent()
{
  sf::Event event;

  while(m_window.pollEvent(event))
  {
		m_gui.handleEvent(event);
		peekState()->handleEvent(event);

    if (event.type == sf::Event::Closed)
      m_window.close();
    if (event.type == sf::Event::Resized)
    {
        // update the view to the new size of the window
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        m_window.setView(sf::View(visibleArea));
    }
  }
}

void Game::handleInput()
{
  peekState()->handleInput();
}

sf::RenderTarget& Game::getRenderTarget()
{
  return m_window;
}

tgui::Gui& Game::getGui()
{
	return m_gui;
}
