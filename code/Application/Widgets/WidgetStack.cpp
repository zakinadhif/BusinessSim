#include "Application/Widgets/WidgetStack.hpp"

WidgetStack::WidgetStack(tgui::Container::Ptr container)
	: m_container(container)
{

}

void WidgetStack::addWidget(tgui::Widget::Ptr widget, const tgui::String& name)
{
	m_container->add(widget, name);

	if (m_widgets.empty())
	{
		widget->setPosition(0, 0);
		m_widgets.push_back(widget);
	}
	else 
	{
		auto lastWidget = m_widgets.back();

		widget->setPosition(0, tgui::bindBottom(lastWidget));
		m_widgets.push_back(widget);
	}
}

void WidgetStack::removeWidget(tgui::Widget::Ptr widget)
{
	m_container->remove(widget);
	reorderWidgets();
}

void WidgetStack::removeAllWidgets()
{
	m_widgets.clear();
	m_container->removeAllWidgets();
}

void WidgetStack::reloadWidgets()
{
	m_container->removeAllWidgets();
	
	for (const auto& widget : m_widgets)
	{
		m_container->add(widget, widget->getWidgetName());
	}
}

void WidgetStack::reorderWidgets()
{
	if (m_widgets.empty()) return;

	for (std::size_t i = 0; i < m_widgets.size(); ++i)
	{
		if (i == 0)
		{
			m_widgets[i]->setPosition(0,0);
		}
		else
		{
			auto previousWidget = m_widgets[i-1];

			m_widgets[i]->setPosition(0, tgui::bindBottom(previousWidget));
		}
	}
}
