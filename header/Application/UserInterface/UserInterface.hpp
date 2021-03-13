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

private:
	void loadFormFiles();
	void loadPages();

	tgui::Group::Ptr m_UIContainer;

	tgui::Group::Ptr m_pageContainer;
	tgui::Group::Ptr m_stockWidgetContainer;

	PageManager m_pageManager;
	StockWidgetList m_stockWidgetList;
};
