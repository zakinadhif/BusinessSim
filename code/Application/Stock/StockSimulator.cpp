#include "Application/Stock/StockSimulator.hpp"
#include "Application/Stock/StockQuote.hpp"

#include <spdlog/spdlog.h>

#include <cmath>

StockSimulator::StockSimulator(int tradingPeriod)
	: tradingPeriod(tradingPeriod)
{

}

void StockSimulator::step()
{
	float growth = std::exp(drift + volatility * boxMullerRandom());
	price = price * std::pow(growth, 1 / static_cast<float>(tradingPeriod));
	pricePoints.push_back(price);

	++stepCount;

	if (stepCount == tradingPeriod)
	{
		StockQuote stockQuote = createStockQuote(
		                            pricePoints.begin(),
		                            pricePoints.end()
		                        );
	
		stockQuotes.push_back(stockQuote);
		pricePoints.clear();

		stepCount = 0;
	}
}

void StockSimulator::setPrice(float price)
{
	this->price = price;
	pricePoints.push_back(price);
	++stepCount;
}

void StockSimulator::setDrift(float drift)
{
	this->drift = drift;
}

void StockSimulator::setVolatility(float volatility)
{
	this->volatility = volatility;
}

float StockSimulator::getPrice() const
{
	return price;
}

float StockSimulator::getDrift() const
{
	return drift;
}

float StockSimulator::getVolatility() const
{
	return volatility;
}

const std::vector<StockQuote>& StockSimulator::getStockQuotes() const
{
	return stockQuotes;
}

const std::vector<float>& StockSimulator::getPricePoints() const
{
	return pricePoints;
}

float StockSimulator::boxMullerRandom()
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
