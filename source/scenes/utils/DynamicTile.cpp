#include "headers/DynamicTile.hpp"

DynamicTile::DynamicTile(float posX, float posY, float size, bool collide, int index)
    : Tile(posX, posY, size, collide, index), currentTextureIndex(0)
{
}

void DynamicTile::update(float deltaTime)
{
    // Logica dell'animazione, se necessario
}

void DynamicTile::draw(sf::RenderWindow& window) const
{
    sf::RectangleShape tileShape(sf::Vector2f(size, size));
    tileShape.setPosition(posX, posY);
    tileShape.setTexture(&textures[currentTextureIndex]);
    window.draw(tileShape);
}

void DynamicTile::addTexture(const sf::Texture& texture)
{
    textures.push_back(texture);
}
