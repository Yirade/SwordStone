#include "headers/Enemy.hpp"

Enemy::Enemy(const std::string& texturePath)
    : AnimatedObject(texturePath)
{
    // Altre inizializzazioni specifiche dell'Enemy
}

void Enemy::attack()
{
    // Implementazione del metodo di attacco dell'enemy
}

void Enemy::update(sf::RenderWindow& window)
{
    AnimatedObject::update();

    if (getCollisionRect().intersects(Player::getInstance(window).getCollisionRect()))
    {
        int damage = 1; /* calcola il danno causato */
        Player::getInstance(window).takeDamage(damage);
    }

    if (m_hp <= 0 && !isDestroyed) {
        isDestroyed = true;
        // Cancella l'oggetto enemy
        // Ricrea l'oggetto enemy dopo 10 secondi in una nuova posizione
        std::thread recreateThread([this]() {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            m_hp = 5/* reinizializza l'HP */;
            isDestroyed = false;
            // Ricrea l'oggetto enemy in una nuova posizione
        });
        recreateThread.detach();
    }
}



void Enemy::render(sf::RenderWindow& window) const
{
    AnimatedObject::render(window);
}

void Enemy::takeDamage(int damage)
{
    m_hp -= damage;
    std::cout << "HP rimasto Nemico: " << m_hp << std::endl;

    if (m_hp <= 0 && !isDestroyed) {
        isDestroyed = true;
        // Cancella l'oggetto enemy
        // Ricrea l'oggetto enemy dopo 10 secondi in una nuova posizione
        std::thread recreateThread([this]() {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            m_hp = 5/* reinizializza l'HP */;
            isDestroyed = false;
            // Ricrea l'oggetto enemy in una nuova posizione
        });
        recreateThread.detach();
    }
}


Enemy& Enemy::getInstance(const std::string& texturePath)
{
    static Enemy instance(texturePath);
    return instance;
}

sf::FloatRect Enemy::getCollisionRect() const
{
    return sprite.getGlobalBounds();
}


