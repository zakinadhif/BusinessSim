#include "Application/Controllers/StockItemController.hpp"

#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/Market/CommodityData.hpp"

#include <fmt/format.h>
#include <TGUI/TGUI.hpp>

#include <string>

StockItemController::StockItemController(CommodityData& commodityData, Commodity& commodity, tgui::Group::Ptr widget)
	: m_commodityData(commodityData)
	, m_commodity(commodity)
	, m_widget(widget)
{
	namespace Components = UIComponentNames;

	m_companyLogo = m_widget->get<tgui::Picture>(Components::STOCK_COMPANY_LOGO);
	m_arrowPicture = m_widget->get<tgui::Picture>(Components::STOCK_ARROW_PICTURE);

	m_priceLabel = m_widget->get<tgui::Label>(Components::STOCK_PRICE_LABEL);
}

void StockItemController::initializeAppearance()
{
	auto companyLogoRenderer = m_companyLogo->getRenderer();

}

void StockItemController::update()
{
	std::string priceString = fmt::format("{:.2f} E", m_commodity.price);

	m_priceLabel->setText(priceString);
}

