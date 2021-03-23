#include "Application/Controllers/StockItemController.hpp"

#include "Application/UserInterface/UIComponentNames.hpp"

#include <fmt/format.h>
#include <TGUI/TGUI.hpp>

#include <string>

StockItemController::StockItemController(Commodity& commodity, tgui::Group::Ptr widget)
	: m_commodity(commodity)
	, m_widget(widget)
{
	namespace Components = UIComponentNames;

	m_companyLogoPicture = m_widget->get<tgui::Picture>(Components::STOCK_COMPANY_LOGO);
	m_arrowUpPicture = m_widget->get<tgui::Picture>(Components::STOCK_ARROW_UP_PICTURE);
	m_arrowDownPicture = m_widget->get<tgui::Picture>(Components::STOCK_ARROW_DOWN_PICTURE);
	m_arrowNonePicture = m_widget->get<tgui::Picture>(Components::STOCK_ARROW_NONE_PICTURE);
	m_priceLabel = m_widget->get<tgui::Label>(Components::STOCK_PRICE_LABEL);
}

void StockItemController::update()
{
	// Clears price direction indicator
	m_arrowUpPicture->setVisible(false);
	m_arrowDownPicture->setVisible(false);
	m_arrowNonePicture->setVisible(false);

	if (m_commodity.price > m_previousPrice)
	{
		m_arrowUpPicture->setVisible(true);
	}
	else if (m_commodity.price < m_previousPrice)
	{
		m_arrowDownPicture->setVisible(true);
	}
	else if (m_commodity.price == m_previousPrice)
	{
		m_arrowNonePicture->setVisible(true);
	}

	std::string priceString = fmt::format("{:.2f} E", m_commodity.price);
	m_priceLabel->setText(priceString);
}

