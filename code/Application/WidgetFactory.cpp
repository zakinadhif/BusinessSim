#include "Application/WidgetFactory.hpp"

#include "Application/Market/Commodity.hpp"
#include "Application/UserInterface/UIFormPaths.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/UserInterface/UIResourceIds.hpp"

#include <TGUI/Widgets/Panel.hpp>
#include <fmt/format.h>

namespace Components = UIComponentNames;
namespace FormPaths = UIFormPaths;
namespace ResourceIDs = UIResourceIds;

tgui::Panel::Ptr createStockWidget(Commodity& commodity, TextureHolder& textureHolder)
{
	auto widget = tgui::Panel::create({"100%", "75"});
	widget->loadWidgetsFromFile(UIFormPaths::STOCK_ITEM);

	auto companyLogo = widget->get<tgui::Picture>(Components::STOCK_COMPANY_LOGO);
	auto priceLabel = widget->get<tgui::Label>(Components::STOCK_PRICE_LABEL);
	auto arrowPicture = widget->get<tgui::Picture>(Components::STOCK_ARROW_PICTURE);

	// This expects the commodity's logo resource ID to be the same with its short name
	auto& companyLogoTexture = textureHolder[commodity.shortName];
	auto& noArrowStableTexture = textureHolder[ResourceIDs::NO_ARROW_STABLE];

	companyLogo->getRenderer()->setTexture(companyLogoTexture);
	arrowPicture->getRenderer()->setTexture(noArrowStableTexture);

	priceLabel->setText(fmt::format("{:.2f} E", commodity.price));

	return widget;
}
