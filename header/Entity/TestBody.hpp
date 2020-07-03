#pragma once

#include <SFML/Graphics.hpp>
#include "External/entt/entt.hpp"

class TestBody
{
private:
    sf::CircleShape circle;
public:
    void draw(sf::RenderTarget& renderTarget);
    void update(sf::Time deltaTime);
    void fixedUpdate(sf::Time deltaTime);
};