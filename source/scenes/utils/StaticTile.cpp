#include "headers/StaticTile.hpp"

StaticTile::StaticTile(float posX, float posY, float size, bool collide, int index, const sf::Texture& texture)
    : Tile(posX, posY, size, collide, index), texture(texture)
{
}

void StaticTile::draw(sf::RenderWindow& window) const
{
    sf::RectangleShape tileShape(sf::Vector2f(size, size));
    tileShape.setPosition(posX, posY);
    tileShape.setTexture(&texture);
    window.draw(tileShape);
}
