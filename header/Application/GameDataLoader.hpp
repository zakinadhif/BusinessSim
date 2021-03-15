#pragma once

#include <string>

struct MarketEvent
{
	int id {};

	std::string headline;

	int marketVolatility {};
	int marketDrive {};	
};

struct CommodityData
{
	std::string shortName;
	std::string name;

	std::string description;
	
	std::string logoPath;

};
