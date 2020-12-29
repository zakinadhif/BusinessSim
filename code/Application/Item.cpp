#include "Application/Item.hpp"
#include "Application/Price/MarketDetails.hpp"
#include "Application/Price/PriceSimulator.hpp"

Item::Item()
{

}

Item::Item(const std::string& name, float initialPrice, MarketDetails marketDetails)
	: name(name)
{
	priceSimulator.setPrice(initialPrice);
	priceSimulator.setVolatility(marketDetails.volatility);
	priceSimulator.setDrift(marketDetails.drift);
}

void Item::step()
{
	priceSimulator.step();
}

std::string Item::getName() const
{
	return name;
}

float Item::getPrice() const
{
	return priceSimulator.getPrice();
}

float Item::getDrift() const
{
	return priceSimulator.getDrift();
}

float Item::getVolatility() const
{
	return priceSimulator.getVolatility();
}

void Item::setName(const std::string& name)
{
	this->name = name;
}

void Item::setPrice(float price)
{
	priceSimulator.setPrice(price);
}

void Item::setDrift(float drift)
{
	priceSimulator.setDrift(drift);
}

void Item::setVolatility(float volatility)
{
	priceSimulator.setVolatility(volatility);
}
