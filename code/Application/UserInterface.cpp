#include "Application/UserInterface.hpp"
#include <TGUI/Exception.hpp>

UserInterface::UserInterface(tgui::Group::Ptr container)
	: container(container)
{
	auto topPanelContainer = tgui::Group::create();
	topPanelContainer->loadWidgetsFromFile("assets/forms/topPanel.txt");
	container->add(topPanelContainer, "topPanelContainer");

	auto bottomPanelContainer = tgui::Group::create();
	bottomPanelContainer->loadWidgetsFromFile("assets/forms/bottomPanel.txt");
	container->add(bottomPanelContainer, "bottomPanelContainer");

	auto middlePanelContainer = tgui::Group::create();
	middlePanelContainer->setPosition("0", "topPanelContainer.topPanel.bottom");
	middlePanelContainer->setSize("100%", "bottomPanelContainer.bottomPanel.top - topPanelContainer.topPanel.bottom");
	container->add(middlePanelContainer, "middlePanelContainer");

	pageManager = new PageManager(middlePanelContainer);

	auto reloadPageButton = tgui::Button::create("R");
	reloadPageButton->setPosition("50% - width / 2", "0");
	reloadPageButton->connect("pressed", 
		[this](){ pageManager->reloadPages(); }
	);
	container->add(reloadPageButton, "reloadPageButton");

	pageManager->addPage("assets/forms/emptyPage.txt", "emptyPage");
	pageManager->setActivePage("emptyPage");
}

UserInterface::~UserInterface()
{
	delete pageManager;
}


