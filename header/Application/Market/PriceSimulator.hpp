#pragma once

#include "Application/GameSettings.hpp"

class PriceSimulator
{
public:
	PriceSimulator(
		float startingPrice = 0.0f,
		float drift = 0.0f,
		float volatility = 0.0f,
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
	float m_price = 0.f;
	float m_drift = 0.f;
	float m_volatility = 0.f;

	const int m_tradingPeriod = 0;

	float boxMullerRandom();
};
