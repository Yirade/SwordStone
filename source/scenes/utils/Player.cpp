#include "headers/Player.hpp"

Player& Player::getInstance(sf::RenderWindow& window)
{
    static Player instance(window);
    return instance;
}

Player::Player(sf::RenderWindow& window)
    : m_window(window)
{
    // Carica i frame dell'animazione idle
    for (int i = 1; i <= 4; ++i)
    {
        sf::Texture texture; 
        //std::string filename = "source/resources/sprites/Dungeon 2/0x72_DungeonTilesetII_v1.6/frames/knight_f_idle_anim_f" + std::to_string(i) + ".png";
        std::string filename = "source/resources/sprites/Asset/Character_animation/priests_idle/priest1/v1/priest1_v1_" + std::to_string(i) + ".png";
        if (!texture.loadFromFile(filename))
        {
            // Gestisci l'errore nel caso la texture non possa essere caricata
            // ...
        }
        m_idleFrames.push_back(texture);
    }

    // Carica i frame dell'animazione idle left
    for (int i = 1; i <= 4; ++i)
    {
        sf::Texture texture; 
        //std::string filename = "source/resources/sprites/Dungeon 2/0x72_DungeonTilesetII_v1.6/frames/knight_f_idle_anim_f" + std::to_string(i) + ".png";
        std::string filename = "source/resources/sprites/Asset/Character_animation/priests_idle/priest1/v1 flipped/priest1_v1_" + std::to_string(i) + ".png";
        if (!texture.loadFromFile(filename))
        {
            // Gestisci l'errore nel caso la texture non possa essere caricata
            // ...
        }
        m_idleFramesLeft.push_back(texture);
    }

    // Carica i frame dell'animazione run
    for (int i = 0; i <= 3; ++i)
    {
        sf::Texture texture;
        std::string filename = "source/resources/sprites/Dungeon 2/0x72_DungeonTilesetII_v1.6/frames/knight_f_run_anim_f" + std::to_string(i) + ".png";
        if (!texture.loadFromFile(filename))
        {
            // Gestisci l'errore nel caso la texture non possa essere caricata
            // ...
        }
        m_runFrames.push_back(texture);
    }

    // Carica il frame dell'animazione hit
    sf::Texture hitTexture;
    if (!hitTexture.loadFromFile("source/resources/sprites/Dungeon 2/0x72_DungeonTilesetII_v1.6/frames/knight_f_hit_anim_f0.png"))
    {
        // Gestisci l'errore nel caso la texture non possa essere caricata
        // ...
    }
    m_hitFrames.push_back(hitTexture);

    m_sprite.setTexture(m_idleFrames[0]);  // Imposta il primo frame dell'animazione idle come texture iniziale

    float scaleFactor = 1;
    m_sprite.setScale(scaleFactor, scaleFactor);

    m_position.x = ((640.f-360.f)+((360.f/256.f)*16)*7);
    m_position.y = (((360.f/256.f)*16)*8);
    m_sprite.setPosition(m_position);

    m_currentFrame = 0;  // Inizia con il primo frame
    m_animationTimer.restart();  // Avvia il timer dell'animazione

    m_currentAnimation = AnimationType::Idle;  // Imposta l'animazione iniziale come idle
    m_currentDirection = Direction::Right;  // Imposta la direzione iniziale come destra

    // Inizializza il rettangolo di collisione utilizzando le dimensioni del personaggio
    m_collisionRect = sf::FloatRect(m_position.x, m_position.y , m_sprite.getGlobalBounds().width , m_sprite.getGlobalBounds().height);

}

Player::~Player()
{
    // Distruttore vuoto
}

void Player::moveUp()
{
    if (m_position.y - m_speed >= 0.f && !CollisionElement::getInstance().checkCollision(sf::FloatRect(m_position.x, m_position.y - m_speed, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height)))
    {
        m_position.y -= m_speed;
        m_sprite.setPosition(m_position);
    }

    // Aggiorna il rettangolo di collisione
    m_collisionRect.top = m_position.y;
    m_collisionRect.left = m_position.x;
}

void Player::moveDown()
{
    float windowHeight = static_cast<float>(m_window.getSize().y);
    float spriteHeight = m_sprite.getGlobalBounds().height;

    if (m_position.y + spriteHeight + m_speed <= windowHeight && !CollisionElement::getInstance().checkCollision(sf::FloatRect(m_position.x, m_position.y + m_speed, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height)))
    {
        m_position.y += m_speed;
        m_sprite.setPosition(m_position);
    }

    // Aggiorna il rettangolo di collisione
    m_collisionRect.top = m_position.y;
    m_collisionRect.left = m_position.x;
}

void Player::moveLeft()
{
    float spriteWidth = m_sprite.getGlobalBounds().width;

    if (m_currentDirection != Direction::Left)
    {
        m_currentDirection = Direction::Left;
        //m_sprite.setScale(-1.f, 1.f);
    }
    else
    {
        if (m_position.x - m_speed >= spriteWidth && !CollisionElement::getInstance().checkCollision(sf::FloatRect(m_position.x - m_speed, m_position.y, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height)))
        //if (m_position.x - 16.f >= spriteWidth && !CollisionElement::getInstance().checkCollision(sf::FloatRect(m_position.x - 20.f, m_position.y, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height)))
        {
            m_position.x -= m_speed;
            m_sprite.setPosition(m_position);
        }
    }

    // Aggiorna il rettangolo di collisione
    m_collisionRect.top = m_position.y;
    m_collisionRect.left = m_position.x;
}

void Player::moveRight()
{
    float windowWidth = static_cast<float>(m_window.getSize().x);
    float spriteWidth = m_sprite.getGlobalBounds().width;

    if (m_currentDirection != Direction::Right)
    {
        m_currentDirection = Direction::Right;
        m_sprite.setScale(1.f, 1.f);
    }
    else
    {
        if (m_position.x + spriteWidth + m_speed <= windowWidth && !CollisionElement::getInstance().checkCollision(sf::FloatRect(m_position.x + m_speed, m_position.y, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height)))
        {
            m_position.x += m_speed;
            m_sprite.setPosition(m_position);
        }
    }

    // Aggiorna il rettangolo di collisione
    m_collisionRect.top = m_position.y;
    m_collisionRect.left = m_position.x;
}

void Player::attack() {

    std::cout << "attack" << std::endl;
    Enemy& enemy = Enemy::getInstance("source/resources/sprites/Asset/Character_animation/monsters_idle/vampire/v2/vampire_v2_");
    enemy.render(m_window);
    enemy.update(m_window);

    static sf::Clock m_damageTimer;
    if (m_isColliding && m_damageTimer.getElapsedTime().asSeconds() >= 1.f) {
            int damage = 1; // Genera un danno random
            enemy.takeDamage(damage);
            std::cout << "attack" << std::endl;
            //m_damagedThisSecond = true; // Imposta il flag di danneggiamento a true
            // m_damageTimer.restart(); // Resetta il timer per il prossimo colpo
        }
}


void Player::stopMovement() {
    m_isMoving = false;
}

void Player::takeDamage(int damage)
{
    m_hp -= damage;
    // Gestisci il danno al player come desiderato (es. riduci i punti vita, controlla se è morto, ecc.)
    std::cout << "HP rimasto: " << m_hp << std::endl;
    m_isDamaged = true;

}

void Player::updateColor()
{
    if (m_isDamaged)
    {
        m_sprite.setColor(sf::Color::Red);
    }
    else
    {
        // Ripristina il colore originale del personaggio
        m_sprite.setColor(sf::Color::White);
    }
}

void Player::update()
{
    // Logica di aggiornamento del player
   
   if (m_isDamaged)
    {
        m_sprite.setColor(sf::Color::Red);
    }
    else
    {
        // Ripristina il colore originale del personaggio
        m_sprite.setColor(sf::Color::White);
    }
    // Cambio dei frame dell'animazione ogni 200 millisecondi per l'animazione idle
    if (m_animationTimer.getElapsedTime().asMilliseconds() >= 200)
    {   
        if (m_currentAnimation == AnimationType::Idle && m_currentDirection == Direction::Right)
        {
            m_currentFrame = (m_currentFrame + 1) % m_idleFrames.size();  // Passa al frame successivo
            m_sprite.setTexture(m_idleFrames[m_currentFrame]);  // Imposta la texture del frame corrente
            m_animationTimer.restart();  // Resetta il timer
        }
        else if (m_currentAnimation == AnimationType::Idle && m_currentDirection == Direction::Left)
        {
            m_currentFrame = (m_currentFrame + 1) % m_idleFramesLeft.size();  // Passa al frame successivo
            m_sprite.setTexture(m_idleFramesLeft[m_currentFrame]);  // Imposta la texture del frame corrente
            m_animationTimer.restart();  // Resetta il timer
        }
        // Gestione dell'animazione di corsa
        else if (m_currentAnimation == AnimationType::Run)
        {
            // Cambio dei frame dell'animazione ogni 100 millisecondi per l'animazione di corsa
            if (m_animationTimer.getElapsedTime().asMilliseconds() >= 100)
            {
                m_currentFrame = (m_currentFrame + 1) % m_runFrames.size();  // Passa al frame successivo
                m_sprite.setTexture(m_runFrames[m_currentFrame]);  // Imposta la texture del frame corrente
                m_animationTimer.restart();  // Resetta il timer
            }
        }

        // Gestione dell'animazione del colpo
        else if (m_currentAnimation == AnimationType::Hit)
        {
            // Mostra il primo frame dell'animazione di colpo
            m_currentFrame = 0;
            m_sprite.setTexture(m_hitFrames[m_currentFrame]);
        }

            // Aggiorna il rettangolo di collisione alla posizione corrente del personaggio
        m_collisionRect = sf::FloatRect(m_position.x, m_position.y, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);

        m_animationTimer.restart(); // Resetta il timer dell'animazione
    }

    Enemy& enemy = Enemy::getInstance("source/resources/sprites/Asset/Character_animation/monsters_idle/vampire/v2/vampire_v2_");
    enemy.setPosition(sf::Vector2f(300.f, 300.f));
    enemy.render(m_window);
    enemy.update(m_window);

    static sf::Clock m_damageTimer; // Timer per gestire l'intervallo tra i colpi
    const sf::Time m_damageInterval = sf::seconds(1.0f); // Intervallo di 1 secondo tra i colpi

    // Controllo della collisione con l'enemy
        if (m_collisionRect.intersects(enemy.getCollisionRect())) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_damageTimer.getElapsedTime() >= m_damageInterval && !m_damagedThisSecond) {
                // Il player preme il tasto spazio, il timer ha superato l'intervallo e non è stato danneggiato in questo secondo
                int damage = 1; // Genera un danno random
                enemy.takeDamage(damage);
                m_damagedThisSecond = true; // Imposta il flag di danneggiamento a true
                m_damageTimer.restart(); // Resetta il timer per il prossimo colpo
            }
            else if (m_damageTimer.getElapsedTime() >= m_damageInterval) {
                // L'enemy tocca il player, il timer ha superato l'intervallo e non è stato danneggiato in questo secondo
                int damage = 1; // Genera un danno random
                takeDamage(damage);
                updateColor();
                m_damagedThisSecond = true; // Imposta il flag di danneggiamento a true
                m_isColliding = true;
                m_damageTimer.restart(); // Resetta il timer per il prossimo colpo
    
            }
        }
        else if (std::abs(m_collisionRect.left - enemy.getCollisionRect().left) <= m_collisionRect.width &&
         std::abs(m_collisionRect.top - enemy.getCollisionRect().top) <= m_collisionRect.height)
        {
            m_isColliding = true;
        }
        else {
            // Se non c'è collisione con l'enemy, resetta il flag di danneggiamento
            m_damagedThisSecond = false;
            m_isDamaged = false;

        }
}


void Player::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}
