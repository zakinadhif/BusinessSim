#pragma once

#include "Application/UserInterface/PageManager.hpp"
#include "Application/UserInterface/StockWidgetList.hpp"

#include <TGUI/TGUI.hpp>

#include <memory>

class UserInterface
{
public:
	UserInterface(tgui::Group::Ptr container);

	tgui::Group::Ptr getUIContainer();

	void addStockWidget(const PriceSimulator& stock, const std::string& name);
	void updateStockWidgetList();

	~UserInterface();
private:
	tgui::Group::Ptr uiContainer;
	StockWidgetList* stockWidgetList;
	PageManager* pageManager;
};
