#pragma once

#include <TGUI/Widgets/Panel.hpp>

#include <optional>
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
	typedef std::tuple<const PriceSimulator&, tgui::Group::Ptr> DataWidgetPair;

	void configureStockWidgetProperties(const std::string& name);
	void updateStockWidget(const std::string& name);

	tgui::Container::Ptr m_container;
	std::unordered_map<std::string, DataWidgetPair> m_dataStockWidgets;

	// Need this to calculate widget position based on previous widget
	tgui::Group::Ptr previousWidget;
};
