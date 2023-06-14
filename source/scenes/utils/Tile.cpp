#include "headers/Tile.hpp"

Tile::Tile(float posX, float posY, float size, bool collide, int index)
    : posX(posX), posY(posY), size(size), collide(collide), index(index)
{
}

float Tile::getSize() const
{
    return size;
}

void Tile::setSize(float size)
{
    this->size = size;
}

float Tile::getPositionX() const
{
    return posX;
}

void Tile::setPositionX(float posX)
{
    this->posX = posX;
}

float Tile::getPositionY() const
{
    return posY;
}

void Tile::setPositionY(float posY)
{
    this->posY = posY;
}

bool Tile::canCollide() const
{
    return collide;
}

void Tile::setCollide(bool collide)
{
    this->collide = collide;
}

int Tile::getIndex() const
{
    return index;
}

void Tile::setIndex(int index)
{
    this->index = index;
}
