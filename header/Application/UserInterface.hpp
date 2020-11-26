#pragma once

#include <TGUI/TGUI.hpp>

class UserInterface
{
public:
	UserInterface();

	UserInterface(tgui::Group::Ptr container);
private:
	tgui::Group::Ptr container;
};
