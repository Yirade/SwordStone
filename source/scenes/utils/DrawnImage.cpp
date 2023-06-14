#include "headers/DrawnImage.hpp"
#include <iostream>

DrawnImage::DrawnImage(sf::RenderWindow& window, const std::string& imagePath, float positionX, float positionY, float width, float height)
    : window(window), imagePath(imagePath), positionX(positionX), positionY(positionY), width(width), height(height)
{
    try {
        if (!texture.loadFromFile(imagePath))
        {
            throw std::runtime_error("Error loading image: " + imagePath);
        }

        sprite.setTexture(texture);
        sprite.setPosition(positionX, positionY);

        if (width > 0 && height > 0) {
            sprite.setScale(width / texture.getSize().x, height / texture.getSize().y);
        }
    }
    catch (const std::exception& e) {
        // Gestisci l'errore se il caricamento dell'immagine fallisce
        // Ad esempio, puoi impostare una texture di fallback o mostrare un messaggio di errore
        std::cout << e.what() << std::endl;
    }
}

DrawnImage::DrawnImage(sf::RenderWindow& window)
    : window(window)
{
}

void DrawnImage::draw()
{
    window.draw(sprite);
}

sf::RenderWindow& DrawnImage::getWindow() const
{
    return window;
}

std::string DrawnImage::getImagePath() const
{
    return imagePath;
}

float DrawnImage::getPositionX() const
{
    return positionX;
}

float DrawnImage::getPositionY() const
{
    return positionY;
}

void DrawnImage::setImagePath(const std::string& imagePath)
{
    this->imagePath = imagePath;

    try {
        if (!texture.loadFromFile(imagePath))
        {
            throw std::runtime_error("Error loading image: " + imagePath);
        }

        sprite.setTexture(texture);
    }
    catch (const std::exception& e) {
        // Gestisci l'errore se il caricamento dell'immagine fallisce
        // Ad esempio, puoi impostare una texture di fallback o mostrare un messaggio di errore
        std::cout << e.what() << std::endl;
    }
}

void DrawnImage::setPositionX(float positionX)
{
    this->positionX = positionX;
    sprite.setPosition(positionX, sprite.getPosition().y);
}

void DrawnImage::setPositionY(float positionY)
{
    this->positionY = positionY;
    sprite.setPosition(sprite.getPosition().x, positionY);
}

float DrawnImage::getWidth() const
{
    return width;
}

float DrawnImage::getHeight() const
{
    return height;
}

void DrawnImage::setWidth(float width)
{
    this->width = width;
    sprite.setScale(width / texture.getSize().x, sprite.getScale().y);
}

void DrawnImage::setHeight(float height)
{
    this->height = height;
    sprite.setScale(sprite.getScale().x, height / texture.getSize().y);
}
