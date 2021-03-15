#pragma once

#include <random>

namespace Random
{
	float getFloat();
	int   getInt();

	std::mt19937& getEngine();
}
