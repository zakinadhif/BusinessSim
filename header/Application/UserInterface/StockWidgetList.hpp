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
	struct StockWidgetData
	{
		StockWidgetData(tgui::Group::Ptr widget, const PriceSimulator& data);

		tgui::Group::Ptr widgetPtr;
		const PriceSimulator& data;
	};

	void updateStockWidget(const std::string& name);
	std::optional<StockWidgetData> tryGetStockWidgetData(const std::string& name);
	std::optional<StockWidgetData> tryGetStockWidgetData(const std::string& name) const;

	tgui::Container::Ptr parentContainer;
	std::unordered_map<std::string, StockWidgetData> stockWidgetDatas;

	// Need this to calculate widget position based on previous widget
	std::string previousWidgetName = "";
};
