#include "Application/UserInterface/StockWidgetList.hpp"
#include "Application/Price/PriceQuote.hpp"
#include "Application/Price/PriceSimulator.hpp"

#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/UserInterface/UIFormPaths.hpp"

#include <TGUI/TGUI.hpp>
#include <spdlog/fmt/bundled/core.h>

StockWidgetList::StockWidgetData::StockWidgetData(tgui::Group::Ptr widget, const PriceSimulator& stockSimulator)
	: widgetPtr(widget), data(stockSimulator)
{

}

StockWidgetList::StockWidgetList(tgui::Container::Ptr parentContainer)
	: parentContainer(parentContainer)
{
}

void StockWidgetList::createStockWidget(const PriceSimulator& stock, const std::string& name)
{
	assert(name != "" && "Stock Widget name can't be empty");

	std::string yOffset = "0";

	if (!previousWidgetName.empty())
	{
		yOffset = std::string() + previousWidgetName + ".bottom";
	}

	tgui::Group::Ptr stockWidget = tgui::Group::create({"100%", "75"});
	parentContainer->add(stockWidget, name);

	stockWidget->setPosition("0", yOffset);

	stockWidget->loadWidgetsFromFile(UIFormPaths::STOCK_ITEM);

	stockWidgetDatas.emplace(std::make_pair(name, StockWidgetData { stockWidget, stock }));


	previousWidgetName = name;  
}

void StockWidgetList::removeStockWidget(const std::string& name)
{
	auto widgetDataOpt = tryGetStockWidgetData(name);
	if (!widgetDataOpt.has_value()) return;

	parentContainer->remove(widgetDataOpt->widgetPtr);
	stockWidgetDatas.erase(name);
}

void StockWidgetList::clearList()
{
	for (auto& widgetData : stockWidgetDatas)
	{
		parentContainer->remove(widgetData.second.widgetPtr);
	}

	stockWidgetDatas.clear();
}

void StockWidgetList::reloadStockWidgets()
{
	for (auto& widgetData : stockWidgetDatas)
	{
		parentContainer->add(widgetData.second.widgetPtr);
	}
}

void StockWidgetList::updateStockWidgets()
{
	for (auto& widgetData : stockWidgetDatas)
	{
		updateStockWidget(widgetData.first);
	}
}

void StockWidgetList::updateStockWidget(const std::string& name)
{
	auto widgetDataOpt = tryGetStockWidgetData(name);
	if (!widgetDataOpt.has_value()) return;

	const PriceSimulator& stockData = widgetDataOpt->data;
	tgui::Group::Ptr stockWidget = widgetDataOpt->widgetPtr;

	if (stockData.getPriceQuotes().size() != 0)
	{
		std::size_t latestIndex = stockData.getPriceQuotes().size() - 1;
		const PriceQuote& latestQuote = 
			stockData.getPriceQuotes().at(latestIndex);

		stockWidget
			->get<tgui::Label>(UIComponentNames::STOCK_OPEN_PRICE_LABEL)
			->setText(fmt::format("{} E", latestQuote.open));

		stockWidget
			->get<tgui::Label>(UIComponentNames::STOCK_CLOSE_PRICE_LABEL)
			->setText(fmt::format("{} E", latestQuote.close));
		
		stockWidget
			->get<tgui::Label>(UIComponentNames::STOCK_HIGH_PRICE_LABEL)
			->setText(fmt::format("{} E", latestQuote.high));
		
		stockWidget
			->get<tgui::Label>(UIComponentNames::STOCK_LOW_PRICE_LABEL)
			->setText(fmt::format("{} E", latestQuote.low));
	}

	stockWidget
		->get<tgui::Label>(UIComponentNames::STOCK_LAST_PRICE_LABEL)
		->setText(fmt::format("{} E", stockData.getPrice()));
}

std::optional<StockWidgetList::StockWidgetData> StockWidgetList::tryGetStockWidgetData(const std::string& name)
{
	auto stockWidgetDataIter = stockWidgetDatas.find(name);

	return stockWidgetDataIter == stockWidgetDatas.end() ? 
		std::optional<StockWidgetData>() : std::make_optional(stockWidgetDataIter->second);
}

std::optional<StockWidgetList::StockWidgetData> StockWidgetList::tryGetStockWidgetData(const std::string& name) const
{
	auto stockWidgetDataIter = stockWidgetDatas.find(name);

	return stockWidgetDataIter == stockWidgetDatas.end() ? 
		std::optional<StockWidgetData>() : std::make_optional(stockWidgetDataIter->second);
}

tgui::Group::Ptr StockWidgetList::getStockWidget(const std::string &name)
{
	std::optional<StockWidgetData> widgetData = tryGetStockWidgetData(name);
	assert(widgetData.has_value() && "Trying to get non-existent stock widget");
	
	return widgetData->widgetPtr;
}

tgui::Group::ConstPtr StockWidgetList::getStockWidget(const std::string &name) const
{
	std::optional<StockWidgetData> widgetData = tryGetStockWidgetData(name);
	assert(widgetData.has_value() && "Trying to get non-existent stock widget");

	return widgetData->widgetPtr;
}
