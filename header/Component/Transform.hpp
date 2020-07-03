#pragma once

#include <SFML/System/Vector2.hpp>

struct Transform
{
    Transform();
    sf::Vector2f location;
    sf::Vector2f scale;
    float rotation;
};