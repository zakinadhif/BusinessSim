#pragma once

#include <functional>
#include <vector>

class PlayerStats
{
public:
	float getHealth() const;
	float getMoney() const;
	float getHappiness() const;
	float getHunger() const;
	int getTicket() const;

	void setHealth(float);
	void setMoney(float);
	void setHappiness(float);
	void setHunger(float);
	void setTicket(int);

	std::size_t addListener(std::function<void(const PlayerStats&)> callback);
	void removeListener(std::size_t index);

	typedef std::function<void(const PlayerStats&)> Listener;

private:
	std::vector<Listener> callbacks;

	void notifyChanges();

	float health{};
	float money{};
	float happiness{};
	float hunger{};
	int ticket{};
};
