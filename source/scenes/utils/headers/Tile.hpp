#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

class Tile
{
public:
    Tile(float posX = 0.0f, float posY = 0.0f, float size = 50.0f, bool collide = false, int index = -1);
    virtual ~Tile() {}

    virtual void update(float deltaTime) {}
    virtual void draw(sf::RenderWindow& window) const {}

    // Getter e setter
    float getSize() const;
    void setSize(float size);

    float getPositionX() const;
    void setPositionX(float posX);

    float getPositionY() const;
    void setPositionY(float posY);

    bool canCollide() const;
    void setCollide(bool collide);

    int getIndex() const;
    void setIndex(int index);

protected:
    float size;
    float posX;
    float posY;
    bool collide;
    int index;
};

#endif // TILE_HPP
