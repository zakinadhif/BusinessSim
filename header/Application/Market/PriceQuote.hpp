#pragma once

#include <vector>
#include <algorithm>

struct PriceQuote
{
	float open = 0;
	float close = 0;
	float high = 0;
	float low = 0;
};

template<class Iterator>
PriceQuote createPriceQuote(Iterator begin, Iterator end)
{
	return PriceQuote
	{
		/* Open  */ *begin,
		/* Close */ *(end-1),
		/* High  */ *std::max_element(begin, end),
		/* Low   */ *std::min_element(begin, end)
	};
}
