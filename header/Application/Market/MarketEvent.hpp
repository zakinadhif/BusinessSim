#pragma once

#include <string>

struct MarketEvent
{
	int id {};

	std::string headline;

	float marketVolatility {};
	float marketDrive {};
	float maxPriceChange {};

	int chance {};

	bool onlyOnce = true;
};
