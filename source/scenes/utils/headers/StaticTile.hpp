#ifndef STATICTILE_HPP
#define STATICTILE_HPP

#include "Tile.hpp"
#include <SFML/Graphics.hpp>

class StaticTile : public Tile
{
public:
    StaticTile(float posX, float posY, float size = 50.0f, bool collide = false, int index = -1, const sf::Texture& texture = sf::Texture());

    void draw(sf::RenderWindow& window) const override;

private:
    sf::Texture texture;
};

#endif // STATICTILE_HPP
