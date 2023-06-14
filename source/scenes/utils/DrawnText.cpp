#include "headers/DrawnText.hpp"
#include <iostream>

DrawnText::DrawnText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, const std::string& position, float positionX, float positionY)
    : window(window), text(text), font(font), fontSize(fontSize), color(color), position(position), positionX(positionX), positionY(positionY)
{

    window.setKeyRepeatEnabled(false);

    // if (!font.loadFromFile(fontPath))
    // {
    //     // Gestisci l'errore se il caricamento del font fallisce
    //     std::cout << "Error in font load" << std::endl;
    // }

    sfText.setFont(font);
    sfText.setString(text);
    sfText.setCharacterSize(fontSize);
    sfText.setFillColor(color);

    // Ottenere le dimensioni del testo
    sf::FloatRect textBounds = sfText.getGlobalBounds();

    // Calcolare la posizione X e Y in base ai parametri
    if (position == "CENTER")
    {
        positionX = (window.getSize().x - textBounds.width) / 2.0f;
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "LEFT")
    {
        positionX = 0.0f;
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "RIGHT")
    {
        positionX = window.getSize().x - textBounds.width;
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "XCENTER")
    {
        positionX = (window.getSize().x - textBounds.width) / 2.0f;
    }
    else if (position == "XLEFT")
    {
        positionX = 0.0f;
    }
    else if (position == "XRIGHT")
    {
        positionX = window.getSize().x - textBounds.width;
    }
    else if (position == "YCENTER")
    {
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "YLEFT")
    {
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "YRIGHT")
    {
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }

    sfText.setPosition(positionX, positionY);
}

DrawnText::DrawnText(sf::RenderWindow& window)
    : window(window)
{
}

void DrawnText::draw()
{
    window.draw(sfText);
}

// Metodi getter
sf::RenderWindow& DrawnText::getWindow() const
{
    return window;
}

std::string DrawnText::getText() const
{
    return text;
}

const sf::Font& DrawnText::getFont() const
{
    return font;
}

unsigned int DrawnText::getFontSize() const
{
    return fontSize;
}

sf::Color DrawnText::getColor() const
{
    return color;
}

std::string DrawnText::getPosition() const
{
    return position;
}

float DrawnText::getPositionX() const
{
    return positionX;
}

float DrawnText::getPositionY() const
{
    return positionY;
}

// Metodi setter
void DrawnText::setText(const std::string& text)
{
    this->text = text;

    sfText.setString(text);
}

void DrawnText::setFont(const sf::Font& font)
{
    this->font = font;

    sfText.setFont(font);
}

void DrawnText::setFontSize(unsigned int fontSize)
{
    this->fontSize = fontSize;

    sfText.setCharacterSize(fontSize);
}

void DrawnText::setColor(const sf::Color& color)
{
    this->color = color;

    sfText.setFillColor(color);
}

void DrawnText::setPosition(const std::string& position)
{
    this->position = position;

    // Ottenere le dimensioni del testo
    sf::FloatRect textBounds = sfText.getGlobalBounds();

    // Calcolare la posizione X e Y in base ai parametri
    if (position == "CENTER")
    {
        positionX = (window.getSize().x - textBounds.width) / 2.0f;
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "LEFT")
    {
        positionX = 0.0f;
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "RIGHT")
    {
        positionX = window.getSize().x - textBounds.width;
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "XCENTER")
    {
        positionX = (window.getSize().x - textBounds.width) / 2.0f;
    }
    else if (position == "XLEFT")
    {
        positionX = 0.0f;
    }
    else if (position == "XRIGHT")
    {
        positionX = window.getSize().x - textBounds.width;
    }
    else if (position == "YCENTER")
    {
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "YLEFT")
    {
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }
    else if (position == "YRIGHT")
    {
        positionY = (window.getSize().y - textBounds.height) / 2.0f;
    }

    this->positionX = positionX;
    this->positionY = positionY;
    sfText.setPosition(positionX, positionY);
}

void DrawnText::setPositionX(float positionX)
{
    this->positionX = positionX;
    sfText.setPosition(positionX, sfText.getGlobalBounds().getPosition().y);
}

void DrawnText::setPositionY(float positionY)
{
    this->positionY = positionY;
    sfText.setPosition( sfText.getGlobalBounds().getPosition().x , positionY);
}


