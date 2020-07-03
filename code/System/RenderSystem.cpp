#include "System/RenderSystem.hpp"

#include "External/entt/entt.hpp"
#include <SFML/Graphics.hpp>

RenderSystem::RenderSystem()
{

}

void RenderSystem::update(entt::registry& registry)
{
}

void RenderSystem::draw(entt::registry& registry, sf::RenderTarget& renderTarget)
{
    auto view = registry.view<sf::Sprite>();
    for (auto entity : view)
    {
        auto &sprite = view.get<sf::Sprite>(entity);
        renderTarget.draw(sprite);
    }
}