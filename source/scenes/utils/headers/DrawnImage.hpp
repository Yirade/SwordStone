#ifndef DRAWNIMAGE_HPP
#define DRAWNIMAGE_HPP

#include <SFML/Graphics.hpp>
#include <string>

class DrawnImage {
public:
    DrawnImage(sf::RenderWindow& window, const std::string& imagePath, float positionX, float positionY, float width = 0, float height = 0);
    DrawnImage(sf::RenderWindow& window);
    void draw();
    sf::RenderWindow& getWindow() const;
    std::string getImagePath() const;
    float getPositionX() const;
    float getPositionY() const;
    void setImagePath(const std::string& imagePath);
    void setPositionX(float positionX);
    void setPositionY(float positionY);
    float getWidth() const;
    float getHeight() const;
    void setWidth(float width);
    void setHeight(float height);

private:
    sf::RenderWindow& window;
    sf::Sprite sprite;
    sf::Texture texture;
    std::string imagePath;
    float positionX;
    float positionY;
    float width;
    float height;
};

#endif // DRAWNIMAGE_HPP
