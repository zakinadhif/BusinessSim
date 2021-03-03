#pragma once

#include <TGUI/AllWidgets.hpp>

class WidgetStack
{
public:
	WidgetStack(tgui::Container::Ptr container);
	WidgetStack(const WidgetStack& copy) = delete;

	void addWidget(tgui::Widget::Ptr widget, const tgui::String& name);
	void removeWidget(tgui::Widget::Ptr widget);
	void removeAllWidgets();

	void reorderWidgets();
	void reloadWidgets();

private:
	std::vector<tgui::Widget::Ptr> m_widgets;

	tgui::Container::Ptr m_container;
};
