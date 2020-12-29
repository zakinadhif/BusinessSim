#pragma once

#include "Application/GameSettings.hpp"
#include "Application/Price/PriceQuote.hpp"
#include "Application/Price/MarketDetails.hpp"
#include "Application/Utility/Random.hpp"

#include <vector>

class PriceSimulator
{
public:
	PriceSimulator(
		float startingPrice = 1.0f,
		MarketDetails marketDetails = {0.01f, 0.02f},
		int tradingPeriod = GameSettings::ONE_DAY_LENGTH
	);

	void setPrice(float price);
	void setDrift(float drift);
	void setVolatility(float volatility);

	float getPrice() const;
	float getDrift() const;
	float getVolatility() const;

	void step();

private:
	float price = 0.f;
	float drift = 0.f;
	float volatility = 0.01f;

	int stepCount = 0;
	const int tradingPeriod = 0;

	Random random;
	
	float boxMullerRandom();
};
