#include "Application/UserInterface/UserInterface.hpp"
#include "Application/PlayerStats.hpp"

#include "Application/Price/PriceSimulator.hpp"
#include "Application/UserInterface/StockWidgetList.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/UserInterface/UIFormPaths.hpp"

#include <TGUI/Exception.hpp>
#include <TGUI/Widgets/Group.hpp>
#include <TGUI/Widgets/VerticalLayout.hpp>

UserInterface::UserInterface(tgui::Group::Ptr uiContainer)
	: uiContainer(uiContainer)
{
	uiContainer->loadWidgetsFromFile("assets/forms/topPanel.txt", false);
	uiContainer->loadWidgetsFromFile("assets/forms/bottomPanel.txt", false);

	auto pageContainer = tgui::Group::create();
	pageContainer->setPosition("0", "topPanel.bottom");
	pageContainer->setSize("100%", "bottomPanel.top - topPanel.bottom");
	uiContainer->add(pageContainer, "pageContainer");

	pageManager = new PageManager(pageContainer);

	auto reloadPageButton = tgui::Button::create("R");
	reloadPageButton->setPosition("50% - width / 2", "0");
	reloadPageButton->connect(
		"pressed",
	    [this]()
		{
			pageManager->reloadPages();
			stockWidgetList->reloadStockWidgets();
		}
    );
	uiContainer->add(reloadPageButton, "reloadPageButton");

	pageManager->addPage(UIFormPaths::EMPTY_PAGE, "Empty Page");
	pageManager->addPage(UIFormPaths::TRADE_MENU, "Trading Menu");
	pageManager->addPage(UIFormPaths::SOCIAL_MENU, "Social Menu");
	pageManager->addPage(UIFormPaths::COMMODITIES_MENU, "Commodities Menu");
	pageManager->setActivePage("Empty Page");
	
	auto tradingButton = uiContainer->get(UIComponentNames::GOTO_TRADING_MENU_BUTTON);
	if (tradingButton) tradingButton->connect("pressed", [this](){pageManager->setActivePage("Trading Menu");});

	auto socialButton = uiContainer->get(UIComponentNames::GOTO_SOCIAL_MENU_BUTTON);
	if (socialButton) socialButton->connect("pressed", [this](){pageManager->setActivePage("Social Menu");});

	auto commoditiesButton = uiContainer->get(UIComponentNames::GOTO_COMMODITIES_MENU_BUTTON);
	if (commoditiesButton) commoditiesButton->connect("pressed", [this](){pageManager->setActivePage("Commodities Menu");});

	stockWidgetList = new StockWidgetList(pageManager->getPage("Trading Menu"));
}

tgui::Group::Ptr UserInterface::getUIContainer()
{
	return uiContainer;
}

void UserInterface::addStockWidget(const PriceSimulator& stock, const std::string& name)
{
	stockWidgetList->createStockWidget(stock, name);
}

void UserInterface::updateStockWidgetList()
{
	stockWidgetList->updateStockWidgets();
}

UserInterface::~UserInterface()
{
	delete stockWidgetList;
	delete pageManager;
}
