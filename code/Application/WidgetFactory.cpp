#include "Application/WidgetFactory.hpp"

#include "Application/Market/Commodity.hpp"
#include "Application/UserInterface/UIFormPaths.hpp"
#include "Application/UserInterface/UIComponentNames.hpp"
#include "Application/UserInterface/UIResourceIds.hpp"

#include <TGUI/Widgets/Panel.hpp>
#include <fmt/format.h>

#include <math.h>

namespace Components = UIComponentNames;
namespace FormPaths = UIFormPaths;
namespace ResourceIDs = UIResourceIds;

tgui::Panel::Ptr createStockWidget(Commodity& commodity, TextureHolder& textureHolder)
{
	auto widget = tgui::Panel::create({"100%", "75"});
	widget->loadWidgetsFromFile(FormPaths::STOCK_ITEM);

	auto companyLogoPicture = widget->get<tgui::Picture>(Components::STOCK_COMPANY_LOGO);
	auto companyLogoFrame = widget->get<tgui::Group>(Components::STOCK_COMPANY_LOGO_FRAME);
	auto priceLabel = widget->get<tgui::Label>(Components::STOCK_PRICE_LABEL);

	// This expects the commodity's logo resource ID to be the same with its short name
	auto& companyLogoTexture = textureHolder[commodity.shortName];

	companyLogoPicture->getRenderer()->setTexture(companyLogoTexture);
	priceLabel->setText(fmt::format("{:.2f} E", commodity.price));

	// Calculate scaling maximum scaling while preserving aspect ratio
	sf::Vector2f companyLogoFrameSize = companyLogoFrame->getSize();
	sf::Vector2f companyLogoTextureSize = static_cast<sf::Vector2f>(companyLogoTexture.getSize());

	float maxScale = std::min(
		companyLogoFrameSize.x / companyLogoTextureSize.x,
		companyLogoFrameSize.y / companyLogoTextureSize.y
	);

	companyLogoPicture->setPosition({0,0});
	companyLogoPicture->setSize(companyLogoTextureSize.x * maxScale, companyLogoTextureSize.y * maxScale);

	return widget;
}
