#pragma once

#include <string>
#include <vector>

struct MarketEvent
{
	int id {};

	std::string headline;

	float marketVolatility {};
	float marketDrive {};

	bool onlyOnce = true;

	int chance {};
};

struct CommodityData
{
	std::string shortName;
	std::string name;

	std::string description;
	
	std::string logoPath;

	std::vector<MarketEvent> events;
};

std::vector<CommodityData> loadCommodities();
