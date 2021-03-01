#include "Application/UserInterface/UserInterface.hpp"
#include "Application/PlayerStats.hpp"

#include "Application/Market/PriceSimulator.hpp"
#include "Application/UserInterface/StockWidgetList.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/UserInterface/UIFormPaths.hpp"

#include <TGUI/Exception.hpp>
#include <TGUI/Widgets/Group.hpp>
#include <TGUI/Widgets/VerticalLayout.hpp>

UserInterface::UserInterface(tgui::Group::Ptr container)
	: m_UIContainer{container}
	, m_pageContainer{tgui::Group::create()}
	, m_stockWidgetContainer{tgui::Group::create()}
	, m_pageManager{m_pageContainer}
	, m_stockWidgetList{m_stockWidgetContainer}
{
	m_UIContainer->loadWidgetsFromFile("assets/forms/topPanel.txt", false);
	m_UIContainer->loadWidgetsFromFile("assets/forms/bottomPanel.txt", false);

	m_pageContainer->setPosition("0", "topPanel.bottom");
	m_pageContainer->setSize("100%", "bottomPanel.top - topPanel.bottom");
	m_UIContainer->add(m_pageContainer, "pageContainer");
	
	auto reloadPageButton = tgui::Button::create("R");
	reloadPageButton->setPosition("50% - width / 2", "0");
	reloadPageButton->connect(
		"pressed",
		[this]()
		{
			m_pageManager.reloadPages();
			m_stockWidgetList.reloadStockWidgets();
		});
	m_UIContainer->add(reloadPageButton, "reloadPageButton");

	m_pageManager.addPage(UIFormPaths::EMPTY_PAGE, "Empty Page");
	m_pageManager.addPage(UIFormPaths::TRADE_MENU, "Trading Menu");
	m_pageManager.addPage(UIFormPaths::SOCIAL_MENU, "Social Menu");
	m_pageManager.addPage(UIFormPaths::COMMODITIES_MENU, "Commodities Menu");
	m_pageManager.setActivePage("Empty Page");

	auto tradingButton = m_UIContainer->get(UIComponentNames::GOTO_TRADING_MENU_BUTTON);
	if (tradingButton) tradingButton->connect("pressed", [this](){m_pageManager.setActivePage("Trading Menu");});

	auto socialButton = m_UIContainer->get(UIComponentNames::GOTO_SOCIAL_MENU_BUTTON);
	if (socialButton) socialButton->connect("pressed", [this](){m_pageManager.setActivePage("Social Menu");});

	auto commoditiesButton = m_UIContainer->get(UIComponentNames::GOTO_COMMODITIES_MENU_BUTTON);
	if (commoditiesButton) commoditiesButton->connect("pressed", [this](){m_pageManager.setActivePage("Commodities Menu");});

	auto tradingPage = m_pageManager.getPage("Trading Menu");
	tradingPage->add(m_stockWidgetContainer);
}

tgui::Group::Ptr UserInterface::getUIContainer()
{
	return m_UIContainer;
}

void UserInterface::addStockWidget(const PriceSimulator& stock, const std::string& name)
{
	m_stockWidgetList.createStockWidget(stock, name);
}

void UserInterface::updateStockWidgetList()
{
	m_stockWidgetList.updateStockWidgets();
}
