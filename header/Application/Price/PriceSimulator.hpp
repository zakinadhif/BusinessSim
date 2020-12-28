#pragma once

#include "Application/GameSettings.hpp"
#include "Application/Price/PriceQuote.hpp"
#include "Application/Utility/Random.hpp"

#include <vector>

class PriceSimulator
{
public:
	PriceSimulator(int tradingPeriod = GameSettings::ONE_DAY_LENGTH);

	void setPrice(float price);
	void setDrift(float drift);
	void setVolatility(float volatility);

	float getPrice() const;     
	float getDrift() const;
	float getVolatility() const;

	void step();

	const std::vector<PriceQuote>& getPriceQuotes() const;
	const std::vector<float>& getPricePoints() const;

private:
	float price = 0.f;
	float drift = 0.f;
	float volatility = 0.01f;

	std::vector<PriceQuote> priceQuotes;
	std::vector<float> pricePoints;

	int stepCount = 0;
	const int tradingPeriod = 0;

	Random random;
	
	float boxMullerRandom();
};
