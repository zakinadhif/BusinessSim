#include "Application/Market/PriceSimulator.hpp"

#include "Application/Utility/Random.hpp"

#include <cmath>

PriceSimulator::PriceSimulator(float initialPrice, float drift, float volatility, int tradingPeriod)
	: m_tradingPeriod{tradingPeriod}
	, m_price{initialPrice}
	, m_drift{drift}
	, m_volatility{volatility}
{
}

void PriceSimulator::step()
{
	float growth = std::exp(m_drift + m_volatility * boxMullerRandom());
	m_price = m_price * std::pow(growth, 1 / static_cast<float>(m_tradingPeriod));
}

void PriceSimulator::setPrice(float price)
{
	m_price = price;
}

void PriceSimulator::setDrift(float drift)
{
	m_drift = drift;
}

void PriceSimulator::setVolatility(float volatility)
{
	m_volatility = volatility;
}

float PriceSimulator::getPrice() const
{
	return m_price;
}

float PriceSimulator::getDrift() const
{
	return m_drift;
}

float PriceSimulator::getVolatility() const
{
	return m_volatility;
}

float PriceSimulator::boxMullerRandom()
{
	float u1 = Random::getFloat();
	float u2 = Random::getFloat();

	float z;
	z = std::sqrt(-2.f * std::log(u1));
	z = z * std::cos(2.f * 3.14159f * u2);

	if (std::isfinite(z))
	{
		return z;
	}

	return boxMullerRandom();
}
