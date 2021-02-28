#include "Application/UserInterface/StockWidgetList.hpp"
#include "Application/Market/PriceQuote.hpp"
#include "Application/Market/PriceSimulator.hpp"

#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/UserInterface/UIFormPaths.hpp"

#include <TGUI/TGUI.hpp>
#include <spdlog/fmt/bundled/core.h>

StockWidgetList::StockWidgetList(tgui::Container::Ptr parentContainer)
	: m_container(parentContainer)
{
}

void StockWidgetList::createStockWidget(const PriceSimulator& stock, const std::string& name)
{
	assert(name != "" && "Stock Widget name can't be empty");

	tgui::Group::Ptr stockWidget = tgui::Group::create({"100%", "75"});
	m_container->add(stockWidget, name);

	if (previousWidget.get())
	{
		stockWidget->setPosition(0, tgui::bindBottom(previousWidget));
	}
	else
	{
		stockWidget->setPosition(0,0);
	}

	stockWidget->loadWidgetsFromFile(UIFormPaths::STOCK_ITEM);

	m_dataStockWidgets.emplace(std::make_pair(name, std::forward_as_tuple(stock, stockWidget)));

	configureStockWidgetProperties(name);

	previousWidget = stockWidget;  
}

void StockWidgetList::removeStockWidget(const std::string& name)
{
	const auto& [stockData, stockWidget] = m_dataStockWidgets.at(name);	
	
	m_container->remove(stockWidget);
	m_dataStockWidgets.erase(name);
}

void StockWidgetList::clearList()
{
	m_container->removeAllWidgets();
	m_dataStockWidgets.clear();
}

void StockWidgetList::reloadStockWidgets()
{
	for (const auto& [stockName, stockWidgetPair] : m_dataStockWidgets)
	{
		const auto& [stockData, stockWidget] = stockWidgetPair;
		m_container->add(stockWidget);
	}
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
		->connect(
		"ValueChanged", 
		[this, buyCountLabel](tgui::Widget::Ptr widget, const std::string& signalName) {
			buyCountLabel->setText(std::to_string(static_cast<int>(widget->cast<tgui::SpinButton>()->getValue())));
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
