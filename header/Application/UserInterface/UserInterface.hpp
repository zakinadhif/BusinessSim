#pragma once

#include "Application/UserInterface/PageManager.hpp"

#include <TGUI/TGUI.hpp>
#include <Thor/Resources.hpp>

#include <memory>

class StockItemController;

struct Commodity;

class UserInterface
{
public:
	UserInterface(tgui::Group::Ptr container);

	tgui::Group::Ptr getUIContainer();

	StockItemController addStockWidget(Commodity& commodity);

private:
	void loadFormFiles();
	void loadPages();

	tgui::Group::Ptr m_UIContainer;
	tgui::Group::Ptr m_pageContainer;
	
	tgui::HorizontalLayout::Ptr m_stockWidgetList;

	PageManager m_pageManager;

	thor::ResourceHolder<sf::Texture, std::string> m_resources;
};
