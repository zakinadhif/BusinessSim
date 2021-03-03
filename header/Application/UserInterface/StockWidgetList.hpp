#pragma once

#include "Application/Widgets/WidgetStack.hpp"

#include <TGUI/Widgets/Panel.hpp>

#include <unordered_map>

class PriceSimulator;

class StockWidgetList
{
public:
	StockWidgetList(tgui::Container::Ptr parentContainer);

	void createStockWidget(const PriceSimulator& stock, const std::string& name);
	void removeStockWidget(const std::string& name);

	tgui::Group::Ptr getStockWidget(const std::string& name);
	tgui::Group::ConstPtr getStockWidget(const std::string& name) const;

	void clearList();
	void reloadStockWidgets();
	void updateStockWidgets();

private:
	WidgetStack m_widgetStack;

	typedef std::tuple<const PriceSimulator&, tgui::Group::Ptr> DataWidgetPair;

	void configureStockWidgetProperties(const std::string& name);
	void updateStockWidget(const std::string& name);

	std::unordered_map<std::string, DataWidgetPair> m_dataStockWidgets;
};
