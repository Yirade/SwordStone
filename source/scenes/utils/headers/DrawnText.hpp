#ifndef DRAWNTEXT_HPP
#define DRAWNTEXT_HPP

#include <SFML/Graphics.hpp>

class DrawnText
{
public:
    // Costruttore
    DrawnText(sf::RenderWindow& window, const std::string& text, const sf::Font& font, unsigned int fontSize, const sf::Color& color, const std::string& position, float positionX, float positionY);
    DrawnText(sf::RenderWindow& window);

    // Metodi getter
    sf::RenderWindow& getWindow() const;
    std::string getText() const;
    const sf::Font& getFont() const;
    unsigned int getFontSize() const;
    sf::Color getColor() const;
    std::string getPosition() const;
    float getPositionX() const;
    float getPositionY() const;

    // Metodi setter
    void setText(const std::string& text);
    void setFont(const sf::Font& font);
    void setFontSize(unsigned int fontSize);
    void setColor(const sf::Color& color);
    void setPosition(const std::string& position);
    void setPositionX(float positionX);
    void setPositionY(float positionY);

    // Altri metodi
    void draw();

private:
    sf::RenderWindow& window;
    std::string text;
    //sf::Font& font;
    unsigned int fontSize;
    sf::Color color;
    std::string position;
    float positionX;
    float positionY;
    sf::Font font;
    sf::Text sfText;

};

#endif  // DRAWNTEXT_HPP
