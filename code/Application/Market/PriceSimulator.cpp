#include "Application/Market/PriceSimulator.hpp"
#include "Application/Market/MarketDetails.hpp"
#include "Application/Market/PriceQuote.hpp"

#include <random>
#include <spdlog/spdlog.h>

#include <cmath>

PriceSimulator::PriceSimulator(float initialPrice, MarketDetails marketDetails, int tradingPeriod)
	: tradingPeriod(tradingPeriod)
{
	setPrice(initialPrice);	
	setDrift(marketDetails.drift);
	setVolatility(marketDetails.volatility);
}

void PriceSimulator::step()
{
	float growth = std::exp(drift + volatility * stdRandom());
	price = price * std::pow(growth, 1 / static_cast<float>(tradingPeriod));

	++stepCount;

	if (stepCount == tradingPeriod)
	{
		stepCount = 0;
	}
}

void PriceSimulator::setPrice(float price)
{
	this->price = price;
}

void PriceSimulator::setDrift(float drift)
{
	this->drift = drift;
}

void PriceSimulator::setVolatility(float volatility)
{
	this->volatility = volatility;
}

float PriceSimulator::getPrice() const
{
	return price;
}

float PriceSimulator::getDrift() const
{
	return drift;
}

float PriceSimulator::getVolatility() const
{
	return volatility;
}

float PriceSimulator::boxMullerRandom()
{
	float u1 = random.getRandomNumber();
	float u2 = random.getRandomNumber();

	float z;
	z = std::sqrt(-2.f * std::log(u1));
	z = z * std::cos(2.f * 3.14159f * u2);

	if (std::isfinite(z))
	{
		return z;
	}

	return boxMullerRandom();
}

float PriceSimulator::stdRandom()
{
	static std::normal_distribution<float> normalDist;
	std::mt19937& randomEngine = random.getRandomEngine();

	return normalDist(randomEngine);
}
