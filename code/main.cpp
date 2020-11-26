#include "Engine/Engine.hpp"
#include "Application/BusinessStrategy.hpp"

#include <SFML/Graphics.hpp>

int main()
{
	Engine engine;
	engine.run<BusinessStrategy>();

	return 0;
}
