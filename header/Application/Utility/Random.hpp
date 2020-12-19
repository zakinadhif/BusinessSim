#pragma once

#include <random>

class Random
{
public:
	static void initialize();

	float getRandomNumber();
	std::mt19937& getRandomEngine();

private:
	static std::mt19937 mersenneTwister;
	static bool initialized;

	std::uniform_real_distribution<float> uniform_distribution;
};
