#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <Thor/Resources.hpp>
#include <TGUI/AllWidgets.hpp>

#include <string>

typedef thor::ResourceHolder<sf::Texture, std::string> TextureHolder;

struct Commodity;

tgui::Panel::Ptr createStockWidget(Commodity& commodity, TextureHolder& textureHolder);
