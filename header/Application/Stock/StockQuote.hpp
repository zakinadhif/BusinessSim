#pragma once

#include <vector>
#include <algorithm>

struct StockQuote
{
	float open = 0;
	float close = 0;
	float high = 0;
	float low = 0;
};

template<class Iterator>
StockQuote createStockQuote(Iterator begin, Iterator end)
{
	return StockQuote
	{
		/* Open  */ *begin,
		/* Close */ *end,
		/* High  */ *std::max_element(begin, end),
		/* Low   */ *std::min_element(begin, end)
	};
}
