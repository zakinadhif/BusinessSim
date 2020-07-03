#pragma once

#include <SFML/Graphics.hpp>
#include "External/entt/entt.hpp"

class RenderSystem
{
    RenderSystem();
    void update(entt::registry& registry);
    void draw(entt::registry& registry, sf::RenderTarget& renderTarget); 
};