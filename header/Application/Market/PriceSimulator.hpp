#pragma once

#include "Application/GameSettings.hpp"
#include "Application/Market/PriceQuote.hpp"
#include "Application/Market/MarketDetails.hpp"
#include "Application/Utility/Random.hpp"

#include <vector>

class PriceSimulator
{
public:
	PriceSimulator(
		float startingPrice = 1.0f,
		MarketDetails marketDetails = {0.01f, 0.02f},
		int tradingPeriod = GameSettings::STOCK_TRADING_LENGTH
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
