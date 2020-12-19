#pragma once

#include "Application/Stock/StockSettings.hpp"
#include "Application/Utility/Random.hpp"

#include <vector>

class StockQuote;

class StockSimulator
{
public:
	StockSimulator(int tradingPeriod = StockSettings::ONE_DAY_LENGTH);

	void setPrice(float price);
	void setDrift(float drift);
	void setVolatility(float volatility);

	float getPrice() const;     
	float getDrift() const;
	float getVolatility() const;

	void step();

	const std::vector<StockQuote>& getStockQuotes() const;
	const std::vector<float>& getPricePoints() const;

private:
	float price = 0.f;
	float drift = 0.f;
	float volatility = 0.01f;

	std::vector<StockQuote> stockQuotes;
	std::vector<float> pricePoints;

	int stepCount = 0;
	const int tradingPeriod = 0;

	Random random;
	
	float boxMullerRandom();
};
