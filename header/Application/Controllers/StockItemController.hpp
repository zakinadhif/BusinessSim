#pragma once

#include "Application/Market/Commodity.hpp"

#include <TGUI/AllWidgets.hpp>

class StockItemController
{
public:
	StockItemController(Commodity& commodity, tgui::Group::Ptr widget);

	const std::string& getName() const { return m_commodity.shortName; }
	const std::string& getFullName() const { return m_commodity.fullName; }	

	void setPrice(float price) { m_commodity.price = price; }
	float getPrice() const { return m_commodity.price; }

	void update();

private:
	Commodity& m_commodity;
	tgui::Group::Ptr m_widget;

	tgui::Picture::Ptr m_companyLogoPicture;

	tgui::Picture::Ptr m_arrowUpPicture;
	tgui::Picture::Ptr m_arrowDownPicture;
	tgui::Picture::Ptr m_arrowNonePicture;

	tgui::Label::Ptr m_priceLabel;

	// For tracking price direction change;
	float m_previousPrice {};
};
