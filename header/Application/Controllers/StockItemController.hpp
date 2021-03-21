#pragma once

#include "Application/Market/Commodity.hpp"

#include <TGUI/AllWidgets.hpp>

struct CommodityData;

class StockItemController
{
public:
	StockItemController(CommodityData& commodityMeta, Commodity& commodity, tgui::Group::Ptr widget);

	void setName(const std::string& name) { m_commodity.name = name; }
	const std::string& getName() const { return m_commodity.name; }

	void setPrice(float price) { m_commodity.price = price; }
	float getPrice() const { return m_commodity.price; }

	void update();

private:
	void initializeAppearance();

	CommodityData& m_commodityData;
	Commodity& m_commodity;
	tgui::Group::Ptr m_widget;

	tgui::Picture::Ptr m_companyLogo;
	tgui::Picture::Ptr m_arrowPicture;

	tgui::Label::Ptr m_priceLabel;
};
