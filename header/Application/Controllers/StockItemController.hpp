#pragma once

#include "Application/Market/Commodity.hpp"

#include <TGUI/AllWidgets.hpp>

class StockItemController
{
public:
	StockItemController(Commodity& commodity, tgui::Group::Ptr widget);

	void setName(const std::string& name) { m_commodity.name = name; }
	const std::string& getName() const { return m_commodity.name; }

	void setPrice(float price) { m_commodity.price = price; }
	float getPrice() const { return m_commodity.price; }

	void update();

private:
	Commodity& m_commodity;
	tgui::Group::Ptr m_widget;

	tgui::Label::Ptr m_companyName;
	tgui::Label::Ptr m_priceTag;
};
