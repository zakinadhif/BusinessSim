#include "Application/UserInterface.hpp"
#include <TGUI/Exception.hpp>

UserInterface::UserInterface() {}

UserInterface::UserInterface(tgui::Group::Ptr container)
	: container(container)
{
	auto topBar = tgui::Group::create();
	topBar->loadWidgetsFromFile("assets/forms/topBar.txt");
	container->add(topBar, "topBar");

	auto bottomBar = tgui::Group::create();
	bottomBar->loadWidgetsFromFile("assets/forms/bottomBar.txt");
	container->add(bottomBar, "bottomBar");
}


