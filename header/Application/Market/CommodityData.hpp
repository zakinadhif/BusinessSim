#pragma once

#include "Application/Market/MarketEvent.hpp"

#include <string>
#include <vector>

struct CommodityData
{
	std::string shortName;
	std::string name;

	std::string description;
	
	std::string logoPath;

	std::vector<MarketEvent> events;
};
