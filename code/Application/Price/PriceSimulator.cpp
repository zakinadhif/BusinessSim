#include "Application/Price/PriceSimulator.hpp"
#include "Application/Price/PriceQuote.hpp"

#include <spdlog/spdlog.h>

#include <cmath>

PriceSimulator::PriceSimulator(int tradingPeriod)
	: tradingPeriod(tradingPeriod)
{

}

void PriceSimulator::step()
{
	float growth = std::exp(drift + volatility * boxMullerRandom());
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
