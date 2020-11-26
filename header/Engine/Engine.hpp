#pragma once

#include <utility>

class Game;

class Engine
{
public:
	Engine();

	template<class T, typename... Args>
	void run(Args&&... args);

	~Engine();
private:
	void routine();

	Game* game;
};

template<class T, typename... Args>
void Engine::run(Args&&... args)
{
	game = new T(std::forward<Args>(args)...);

	routine();
}
