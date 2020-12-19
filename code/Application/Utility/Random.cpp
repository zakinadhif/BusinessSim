#include "Application/Utility/Random.hpp"

#include <cassert>
#include <random>

bool Random::initialized = false;
std::mt19937 Random::mersenneTwister; 

void Random::initialize()
{
	assert(!initialized && "Hm, Code smell, RANDOM IS ALREADY INITIALIZED!");

	mersenneTwister.seed(std::random_device{}());
	initialized = true;
}

float Random::getRandomNumber()
{
	return uniform_distribution(getRandomEngine());
}

std::mt19937& Random::getRandomEngine()
{
	assert(initialized && "Random engine hasn't been initialized yet.");

	return mersenneTwister;
}
