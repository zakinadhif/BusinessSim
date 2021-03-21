#pragma once

#include "Application/Market/MarketEvent.hpp"

#include <vector>
#include <string>

struct Commodity
{
	float price;

	const std::string shortName;
	const std::string fullName;

	const std::string description;
	
	const std::string logoPath;

	const std::vector<MarketEvent> events;
};
