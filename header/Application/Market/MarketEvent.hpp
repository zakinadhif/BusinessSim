#pragma once

#include <string>

struct MarketEvent
{
	int id {};

	std::string headline;

	float marketVolatility {};
	float marketDrive {};

	bool onlyOnce = true;

	int chance {};
};
