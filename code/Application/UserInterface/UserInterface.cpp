#include "Application/UserInterface/UserInterface.hpp"
#include "Application/PlayerStats.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"
#include <TGUI/Exception.hpp>
#include <TGUI/Widgets/Group.hpp>

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
		}
    );
	uiContainer->add(reloadPageButton, "reloadPageButton");

	pageManager->addPage("assets/forms/emptyPage.txt", "Empty Page");
	pageManager->addPage("assets/forms/tradingMenu.txt", "Trading Menu");
	pageManager->addPage("assets/forms/socialPage.txt", "Social Menu");
	pageManager->addPage("assets/forms/commoditiesPage.txt", "Commodities Menu");
	pageManager->setActivePage("Empty Page");
	
	auto tradingButton = uiContainer->get(UIComponentNames::SWITCH_TRADING_MENU_BUTTON);
	if (tradingButton) tradingButton->connect("pressed", [this](){pageManager->setActivePage("Trading Menu");});

	auto socialButton = uiContainer->get(UIComponentNames::SWITCH_SOCIAL_MENU_BUTTON);
	if (socialButton) socialButton->connect("pressed", [this](){pageManager->setActivePage("Social Menu");});

	auto commoditiesButton = uiContainer->get(UIComponentNames::SWITCH_COMMODITIES_MENU_BUTTON);
	if (commoditiesButton) commoditiesButton->connect("pressed", [this](){pageManager->setActivePage("Commodities Menu");});
}

tgui::Group::Ptr UserInterface::getUIContainer()
{
	return uiContainer;
}

UserInterface::~UserInterface()
{
	delete pageManager;
}
