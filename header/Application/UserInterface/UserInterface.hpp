#pragma once

#include "Application/UserInterface/PageManager.hpp"

#include <TGUI/TGUI.hpp>

#include <memory>

class UserInterface
{
public:
	UserInterface(tgui::Group::Ptr container);

	tgui::Group::Ptr getUIContainer();

	~UserInterface();
private:
	tgui::Group::Ptr uiContainer;
	PageManager* pageManager;
};
