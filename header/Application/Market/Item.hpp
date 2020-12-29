#pragma once

#include "Application/Market/PriceSimulator.hpp"

class MarketDetails;

class Item
{
public:
	Item();

	Item(const std::string& name, float price, MarketDetails marketDetails);
	
	void step();
	
	std::string getName() const;
	void setName(const std::string& name);

	float getPrice() const;
	float getVolatility() const;
	float getDrift() const;

	void setPrice(float price);
	void setVolatility(float volatility);
	void setDrift(float drift);

private:
	std::string name;
	
	PriceSimulator priceSimulator;
};
