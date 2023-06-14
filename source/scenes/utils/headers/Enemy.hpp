#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AnimatedObject.hpp"
#include "Player.hpp" // Aggiungi l'inclusione del file Player.hpp
#include <iostream>
#include <thread>

class Enemy : public AnimatedObject
{
public:
    Enemy(const std::string& texturePath);
    Enemy();

    void attack();
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window) const;
    void setHP(int hp) { m_hp = hp; }
    int getHP() const { return m_hp; }
    void takeDamage(int damage);
    static Enemy& getInstance(const std::string& texturePath);
    sf::FloatRect getCollisionRect() const;

private:
    int hp = 5;
    int m_hp = 5;
    bool isDestroyed;

};

#endif // ENEMY_HPP
