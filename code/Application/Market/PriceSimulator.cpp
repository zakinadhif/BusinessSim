#include "Application/Market/PriceSimulator.hpp"

#include "Application/GameSettings.hpp"
#include "Application/Utility/Random.hpp"

#include <cmath>

static float boxMullerRandom()
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

float simulateNextPrice(float priceNow, float drift, float volatility)
{
	float growth = std::exp(drift + volatility * boxMullerRandom());
	return priceNow * std::pow(growth, 1 / static_cast<float>(GameSettings::STOCK_TRADING_LENGTH));
}
