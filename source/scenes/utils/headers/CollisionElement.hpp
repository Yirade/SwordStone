#ifndef COLLISIONELEMENT_H
#define COLLISIONELEMENT_H

#include <SFML/Graphics.hpp>
#include <vector>

class CollisionElement
{
public:
    static CollisionElement& getInstance();

    void addElement(const sf::FloatRect& rect);
    bool checkCollision(const sf::FloatRect& otherRect) const;
    void draw(sf::RenderWindow& window) const;
    //void addElement(const sf::FloatRect& rect);

private:
    CollisionElement(); // Costruttore privato per impedire l'istanziazione diretta
    static CollisionElement* instance; // Puntatore all'istanza unica

    std::vector<sf::FloatRect> collisionElements; // Vettore degli elementi di collisione
};

#endif // COLLISIONELEMENT_H
