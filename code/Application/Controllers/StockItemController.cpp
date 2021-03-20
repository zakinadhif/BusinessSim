#include "Application/Controllers/StockItemController.hpp"

#include "Application/UserInterface/UIComponentNames.hpp"

#include <fmt/format.h>

#include <string>

StockItemController::StockItemController(Commodity& commodity, tgui::Group::Ptr widget)
	: m_commodity(commodity)
	, m_widget(widget)
{
	namespace Components = UIComponentNames;
	
	m_companyName = m_widget->get<tgui::Label>(Components::STOCK_COMPANY_NAME);
	m_priceTag = m_widget->get<tgui::Label>(Components::STOCK_LAST_PRICE_LABEL);
}

void StockItemController::update()
{
	std::string priceString = fmt::format("{:.2f} E", m_commodity.price);

	m_companyName->setText(m_commodity.name);
	m_priceTag->setText(priceString);
}

