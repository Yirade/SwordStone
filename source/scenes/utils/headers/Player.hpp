#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "CollisionElement.hpp"
#include "Enemy.hpp"
#include "AnimatedObject.hpp"
#include <iostream>

enum class AnimationType
{
    Idle,
    Run,
    Hit
};

enum class Direction
{
    Left,
    Right
};

class Player
{
public:
    static Player& getInstance(sf::RenderWindow& window);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void attack();
    void update();
    void draw(sf::RenderWindow& window);

    bool checkCollisionWithElements(const sf::FloatRect& otherRect);
    const sf::FloatRect& getCollisionRect() const {
        return m_collisionRect;
    }
    void stopMovement();

    void setHP(int hp) { m_hp = hp; }
    int getHP() const { return m_hp; }
    void takeDamage(int damage);
    void updateColor();

    // sf::Sprite& getSprite();
    // const sf::Sprite& getSprite() const;


private:
    Player(sf::RenderWindow& window);
    ~Player();

    sf::RenderWindow& m_window;
    sf::Sprite m_sprite;
    std::vector<sf::Texture> m_idleFrames;  // Vettore di texture per i frame dell'animazione idle
    std::vector<sf::Texture> m_idleFramesLeft;  // Vettore di texture per i frame dell'animazione idle
    std::vector<sf::Texture> m_runFrames;   // Vettore di texture per i frame dell'animazione run
    std::vector<sf::Texture> m_hitFrames;   // Vettore di texture per i frame dell'animazione hit
    sf::Vector2f m_position;
    int m_hp = 100;

    int m_currentFrame;  // Frame corrente dell'animazione
    sf::Clock m_animationTimer;  // Timer per il cambio dei frame
    AnimationType m_currentAnimation;  // Animazione corrente
    Direction m_currentDirection;  // Direzione corrente
    sf::FloatRect m_collisionRect; // Dichiarazione del rettangolo di collisione
    bool m_isMoving; // Flag per indicare se il personaggio sta muovendo
    std::vector<CollisionElement> collisionElements; // Variabile globale per gli elementi di collisione
    float m_speed = ((360.f/256.f)*16); // Velocità del personaggio
    sf::Clock damageTimer; // Variabile di tempo per tracciare il tempo trascorso dall'ultimo danno
    sf::Time damageDelay = sf::seconds(1.0f);  // Intervallo di tempo richiesto tra i danni
    bool m_damagedThisSecond = false;
    bool m_isDamaged = false;
    bool m_isColliding = false;

};

#endif // PLAYER_HPP
