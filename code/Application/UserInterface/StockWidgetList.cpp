#include "Application/UserInterface/StockWidgetList.hpp"
#include "Application/Market/PriceQuote.hpp"
#include "Application/Market/PriceSimulator.hpp"

#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/UserInterface/UIFormPaths.hpp"

#include <TGUI/TGUI.hpp>
#include <fmt/format.h>

StockWidgetList::StockWidgetList(tgui::Container::Ptr parentContainer)
	: m_widgetStack(parentContainer)
{
}

void StockWidgetList::createStockWidget(const PriceSimulator& stock, const std::string& name)
{
	assert(name != "" && "Stock Widget name can't be empty");

	auto stockWidget = tgui::Group::create({"100%", "75"});
	stockWidget->loadWidgetsFromFile(UIFormPaths::STOCK_ITEM);

	m_widgetStack.addWidget(stockWidget, name);

	m_dataStockWidgets.emplace(std::make_pair(name, std::forward_as_tuple(stock, stockWidget)));
	configureStockWidgetProperties(name);
}

void StockWidgetList::removeStockWidget(const std::string& name)
{
	const auto& [stockData, stockWidget] = m_dataStockWidgets.at(name);	
	
	m_widgetStack.removeWidget(stockWidget);
	m_dataStockWidgets.erase(name);
}

void StockWidgetList::clearList()
{
	m_widgetStack.removeAllWidgets();
	m_dataStockWidgets.clear();
}

void StockWidgetList::reloadStockWidgets()
{
	m_widgetStack.reloadWidgets();
}

void StockWidgetList::updateStockWidgets()
{
	for (const auto& [widgetName, dataWidgetPair] : m_dataStockWidgets)
	{
		updateStockWidget(widgetName);
	}
}

void StockWidgetList::configureStockWidgetProperties(const std::string& name)
{
	auto& [stockData, stockWidget] = m_dataStockWidgets.at(name);

	stockWidget
		->get<tgui::Label>(UIComponentNames::STOCK_COMPANY_NAME)
		->setText(name);

	tgui::Label::Ptr 
		buyCountLabel = stockWidget->get<tgui::Label>(UIComponentNames::STOCK_BUY_COUNT_LABEL);

	stockWidget
		->get<tgui::SpinButton>(UIComponentNames::STOCK_BUY_COUNT_SPIN)
		->onValueChange( 
		[this, buyCountLabel](float value) {
			buyCountLabel->setText(tgui::String::fromNumber(value));
		}
	);
}

void StockWidgetList::updateStockWidget(const std::string& name)
{
	auto& [stockData, stockWidget] = m_dataStockWidgets.at(name);

	stockWidget
		->get<tgui::Label>(UIComponentNames::STOCK_LAST_PRICE_LABEL)
		->setText(fmt::format("{:.2f} E", stockData.getPrice()));
}

tgui::Group::Ptr StockWidgetList::getStockWidget(const std::string &name)
{
	return std::get<1>(m_dataStockWidgets.at(name));
}

tgui::Group::ConstPtr StockWidgetList::getStockWidget(const std::string &name) const
{
	return std::get<1>(m_dataStockWidgets.at(name));
}
