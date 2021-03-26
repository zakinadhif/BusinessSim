#include "Application/UserInterface/UserInterface.hpp"

#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/UserInterface/UIFormPaths.hpp"

#include "Application/Market/PriceSimulator.hpp"
#include "Application/Market/Commodity.hpp"

#include "Application/PlayerStats.hpp"
#include "Application/WidgetFactory.hpp"

#include "Application/Controllers/StockItemController.hpp"

#include <TGUI/TGUI.hpp>
#include <Thor/Resources.hpp>

UserInterface::UserInterface(tgui::Group::Ptr container)
	: m_UIContainer{container}
	, m_pageContainer{tgui::Group::create()}
	, m_stockWidgetsPanel{tgui::ScrollablePanel::create()}
	, m_stockWidgetList{m_stockWidgetsPanel}
	, m_pageManager{m_pageContainer}
{
	namespace Components = UIComponentNames;

	loadFormFiles();
	loadPages();

	m_pageManager.setActivePage("Empty Page");

	// Configure m_pageContainer placement.
	m_pageContainer->setPosition("0", "topPanel.bottom");
	m_pageContainer->setSize("100%", "bottomPanel.top - topPanel.bottom");
	m_UIContainer->add(m_pageContainer, "pageContainer");

	// Wires up bottom panel's buttons.
	auto tradingButton = m_UIContainer->get<tgui::Button>(Components::GOTO_TRADING_MENU_BUTTON);
	auto socialButton = m_UIContainer->get<tgui::Button>(Components::GOTO_SOCIAL_MENU_BUTTON);
	auto commoditiesButton = m_UIContainer->get<tgui::Button>(Components::GOTO_COMMODITIES_MENU_BUTTON);
	
	tradingButton->onClick(
		[this]() {
			m_pageManager.setActivePage("Trading Menu"); 
		}
	);

	socialButton->onClick(
		[this]() {
			m_pageManager.setActivePage("Social Menu");
		}
	);

	commoditiesButton->onClick(
		[this]() {
			m_pageManager.setActivePage("Commodities Menu");
		}
	);

	m_stockWidgetsPanel->getRenderer()->setBackgroundColor(sf::Color(0, 0, 0, 0));

	auto tradingPage = m_pageManager.getPage("Trading Menu");
	tradingPage->get<tgui::Panel>("Panel1")->add(m_stockWidgetsPanel);
}

void UserInterface::loadFormFiles()
{
	namespace FormPaths = UIFormPaths;

	m_UIContainer->loadWidgetsFromFile(FormPaths::TOP_PANEL, false);
	m_UIContainer->loadWidgetsFromFile(FormPaths::BOTTOM_PANEL, false);
}

void UserInterface::loadPages()
{
	namespace FormPaths = UIFormPaths;
	
	m_pageManager.addPage(FormPaths::EMPTY_PAGE, "Empty Page");
	m_pageManager.addPage(FormPaths::TRADE_MENU, "Trading Menu");
	m_pageManager.addPage(FormPaths::SOCIAL_MENU, "Social Menu");
	m_pageManager.addPage(FormPaths::COMMODITIES_MENU, "Commodities Menu");
}

StockItemController UserInterface::addStockWidget(Commodity &commodity)
{
	// Load widget's resource
	m_resources.acquire(
		commodity.shortName, 
		thor::Resources::fromFile<sf::Texture>(commodity.logoPath)
	);

	auto stockWidget = createStockWidget(commodity, m_resources);

	m_stockWidgetList.addWidget(stockWidget, commodity.shortName);

	return StockItemController(commodity, stockWidget);
}

tgui::Group::Ptr UserInterface::getUIContainer()
{
	return m_UIContainer;
}
