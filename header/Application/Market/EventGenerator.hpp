#pragma once

#include "Application/Market/MarketEvent.hpp"

#include <vector>

class EventGenerator
{
public:
	EventGenerator(std::vector<MarketEvent> eventList);

	MarketEvent generateEvent();
};
