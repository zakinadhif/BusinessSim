#include "Application/PlayerStats.hpp"

float PlayerStats::getHealth() const { return health; }
float PlayerStats::getMoney() const { return money; }
float PlayerStats::getHappiness() const { return happiness; }
float PlayerStats::getHunger() const { return hunger; }
int PlayerStats::getTicket() const { return ticket; }

void PlayerStats::setHealth(float health)
{
	this->health = health;
	notifyChanges();
}

void PlayerStats::setMoney(float money)
{
	this->money = money;
	notifyChanges();
}

void PlayerStats::setHappiness(float happiness)
{
	this->happiness = happiness;
	notifyChanges();
}

void PlayerStats::setHunger(float hunger)
{
	this->hunger = hunger;
	notifyChanges();
}

void PlayerStats::setTicket(int ticket)
{
	this->ticket = ticket;
	notifyChanges();
}

std::size_t PlayerStats::addListener(std::function<void (const PlayerStats &)> callback)
{
	callbacks.push_back(callback);
	return callbacks.size() - 1;
}

void PlayerStats::removeListener(std::size_t index)
{
	callbacks.erase(callbacks.begin() + index);
}

void PlayerStats::notifyChanges()
{
	for (auto& callback : callbacks)
	{
		callback(*this);
	}
}
