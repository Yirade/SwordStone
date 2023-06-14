#include "headers/Game.hpp"
#include "headers/Character.hpp"
#include "utils/headers/Player.hpp"
#include "utils/headers/CollisionElement.hpp"

Game::Game(sf::RenderWindow& window, sf::Event& event)
    : window(window), event(event), map(window), background(window) {
    // Inizializza le variabili del gioco
}

void Game::start() {
    // Avvia il gioco
    sf::Clock clock;

    // Inizializza la musica
    MusicPlayer& musicPlayer = MusicPlayer::getInstance();

    // Riproduci una canzone
    musicPlayer.playMusic("source/resources/music/xDeviruchi - Mysterious Dungeon.wav");

    // Ottieni l'istanza del player
    //player = Player::getInstance();

    // Aggiungi un nuovo oggetto Enemy al vettore
    Enemy newEnemy("source/resources/sprites/Asset/Character_animation/monsters_idle/vampire/v2/vampire_v2_");
    newEnemy.setPosition(((640.f-360.f)+((360.f/256.f)*16)*7), (((360.f/256.f)*16)*3));
    enemies.push_back(newEnemy);

    Enemy newEnemy2("source/resources/sprites/Asset/Character_animation/monsters_idle/skeleton1/v2/skeleton_v2_");
    newEnemy2.setPosition(((640.f-360.f)+((360.f/256.f)*16)*2), (((360.f/256.f)*16)*8));
    enemies.push_back(newEnemy2);

    // Aggiungi un nuovo oggetto AnimatedObject al vettore
    AnimatedObject torch1("source/resources/sprites/Asset/items and trap_animation/coin/coin_");
    torch1.setPosition(((643.f-360.f)+((360.f/256.f)*16)*13), (((360.f/256.f)*16)*8)+1);
    animatedObjects.push_back(torch1);

    AnimatedObject torch2("source/resources/sprites/Asset/items and trap_animation/torch/side_torch_");
    torch2.setPosition(((640.f-360.f)+((360.f/256.f)*16)*1), (((360.f/256.f)*16)*7));
    animatedObjects.push_back(torch2);

    AnimatedObject torch3("source/resources/sprites/Asset/items and trap_animation/torch/candlestick_2_");
    torch3.setPosition(((643.f-360.f)+((360.f/256.f)*16)*12), (((360.f/256.f)*16)*7));
    animatedObjects.push_back(torch3);

    AnimatedObject flag1("source/resources/sprites/Asset/items and trap_animation/flag/flag_");
    flag1.setPosition((((640.f-360.f)+((360.f/256.f)*16)*2)+3), (((360.f/256.f)*16)*6)+1);
    animatedObjects.push_back(flag1);

    AnimatedObject flag2("source/resources/sprites/Asset/items and trap_animation/flag/flag_");
    flag2.setPosition(((640.f-360.f)+(((360.f/256.f)*16)*13)+3), (((360.f/256.f)*16)*6)+1);
    animatedObjects.push_back(flag2);

    // AnimatedObject flag1("source/resources/sprites/Asset/items and trap_animation/flag/flag_");
    // flag1.setPosition(((640.f-360.f)+((360.f/256.f)*16)*2), (((360.f/256.f)*16)*6));
    // animatedObjects.push_back(flag1);
    // AnimatedObject flag2("source/resources/sprites/Asset/items and trap_animation/flag/flag_");
    // flag2.setPosition(((640.f-360.f)+((360.f/256.f)*16)*13), (((360.f/256.f)*16)*6));
    // animatedObjects.push_back(flag2);

    

    while (window.isOpen()) {

        sf::Time elapsed = clock.restart(); // Calcolo del tempo trascorso dall'ultimo ciclo
        deltaTime = elapsed.asSeconds(); // Conversione di sf::Time a float

        // Ottieni l'istanza del player
        //Player& player = Player::getInstance(window);

        // Disegna la mappa
        map.setImagePath("source/resources/sprites/maps/map.png");
        map.setHeight(360);
        map.setWidth(360);
        map.setPositionX(640-360);

        // Disegna lo sfondo
        background.setImagePath("source/resources/sprites/UI/side1.png");

        // Crea gli elementi di collisione                                            // x, y, width, height
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*0), (((360.f/256.f)*16)*6), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*5)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*4), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*2), (((360.f/256.f)*16)*7)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*4), (((360.f/256.f)*16)*9), (((360.f/256.f)*16)*2), (((360.f/256.f)*16)*7)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*6), (((360.f/256.f)*16)*5), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*2)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*6), (((360.f/256.f)*16)*10), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*2)));

        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*15), (((360.f/256.f)*16)*6), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*5)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*10), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*2), (((360.f/256.f)*16)*7)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*10), (((360.f/256.f)*16)*9), (((360.f/256.f)*16)*2), (((360.f/256.f)*16)*7)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*9), (((360.f/256.f)*16)*5), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*2)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*9), (((360.f/256.f)*16)*10), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*2)));
        
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*1), (((360.f/256.f)*16)*6), (((360.f/256.f)*16)*3), (((360.f/256.f)*16)*1)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*6), (((360.f/256.f)*16)*1), (((360.f/256.f)*16)*4), (((360.f/256.f)*16)*1)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*12), (((360.f/256.f)*16)*6), (((360.f/256.f)*16)*3), (((360.f/256.f)*16)*1)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*1), (((360.f/256.f)*16)*10), (((360.f/256.f)*16)*3), (((360.f/256.f)*16)*1)));
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*6), (((360.f/256.f)*16)*15), (((360.f/256.f)*16)*4), (((360.f/256.f)*16)*1)));        
        CollisionElement::getInstance().addElement(sf::FloatRect(((640.f-360.f)+((360.f/256.f)*16)*12), (((360.f/256.f)*16)*10), (((360.f/256.f)*16)*3), (((360.f/256.f)*16)*1)));        

        // Aggiungi un nuovo oggetto AnimatedObject al vettore
        // AnimatedObject torch("source/resources/sprites/Asset/items and trap_animation/torch/side_torch_");
        // torch.setPosition(((640.f-360.f)+((360.f/256.f)*16)*1), (((360.f/256.f)*16)*7));
        // animatedObjects.push_back(torch);

        // AnimatedObject torch2("source/resources/sprites/Asset/items and trap_animation/torch/side_torch_");
        // torch2.setPosition(((640.f-360.f)+((360.f/256.f)*16)*14), (((360.f/256.f)*16)*7));
        // animatedObjects.push_back(torch2);
        // Ottieni l'istanza del player e passa la collezione di elementi di collisione
        Player& player = Player::getInstance(window);

        // Aggiorna tutti i nemici nel vettore
        for (Enemy& enemy : enemies) {
            enemy.update(window);
        }

        // Aggiorna tutti i oggetti animati nel vettore
        for (AnimatedObject& animatedObject : animatedObjects) {
            animatedObject.update();
        }


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Gestisci l'input per il personaggio
            //character.handleInput(event, deltaTime);
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                    player.moveUp();
                else if (event.key.code == sf::Keyboard::S)
                    player.moveDown();
                else if (event.key.code == sf::Keyboard::A)
                    player.moveLeft();
                else if (event.key.code == sf::Keyboard::D)
                    player.moveRight();
                else if (event.key.code == sf::Keyboard::Space)
                    player.attack();
            }
        }

        update();
        render();

        // Controlla la collisione tra il giocatore e l'elemento di collisione
        // if (collisionElement.checkCollision(player.getCollisionRect())) {
        //     // Gestisci la collisione come desideri
        //     // ...
        // }
    }
}

void Game::update() {
    // Aggiorna la logica del gioco
    // ...

    // Ottieni l'istanza del player
    Player& player = Player::getInstance(window);
    // Aggiorna il player
    player.update();

    // Aggiorna tutti i nemici nel vettore
    for (Enemy& enemy : enemies) {
        enemy.update(window);
    }

    // Aggiorna gli oggetti animati
    for (AnimatedObject& animatedObject : animatedObjects) {
        animatedObject.update();
    }

    // Crea un elemento di collisione
    // sf::FloatRect collisionRect(10.f, 10.f, 100.f, 100.f);
    // CollisionElement collisionElement(collisionRect);

    // Controlla la collisione tra il giocatore e l'elemento di collisione
    // if (collisionElement.checkCollision(player.getCollisionRect())) {
    //     // Gestisci la collisione come desideri
    //     // ...
    //     // Ad esempio, puoi impedire al personaggio di muoversi in quella direzione
    //     player.stopMovement();
    // }
}


void Game::render() {
    // Effettua il rendering degli elementi di gioco
    window.clear(sf::Color::Black);

    

    // Disegna la mappa
    map.draw();

    background.draw();

    // Ottieni l'istanza del player
    Player& player = Player::getInstance(window);

    // Disegna tutti i nemici nel vettore
    for (const Enemy& enemy : enemies) {
        enemy.render(window);
    }

    // Disegni tutti i oggetti animati
    for (const AnimatedObject& animatedObject : animatedObjects) {
        animatedObject.render(window);
    }

    // Disegna gli elementi di collisione
    //CollisionElement::getInstance().draw(window);
    const std::vector<sf::Font>& fonts = FontLoader::getFonts();
    DrawnText test(window);
    test.setText("Player");
    test.setFont(fonts[1]);
    test.setFontSize(20);
    test.setColor(sf::Color(0, 0, 0, 255));
    //test.setPosition("XCENTER");
    test.setPositionY(50.0f);
    test.setPositionX(110.0f);
    test.draw();

    DrawnText test2(window);
    test2.setText("Health");
    test2.setFont(fonts[1]);
    test2.setFontSize(20);
    test2.setColor(sf::Color(0, 0, 0, 255));
    //test.setPosition("XCENTER");
    test2.setPositionY(105.0f);
    test2.setPositionX(55.0f);
    test2.draw();

    DrawnText test3(window);
    test3.setText("Inventory");
    test3.setFont(fonts[1]);
    test3.setFontSize(20);
    test3.setColor(sf::Color(0, 0, 0, 255));
    //test.setPosition("XCENTER");
    test3.setPositionY(160.0f);
    test3.setPositionX(55.0f);
    test3.draw();

    DrawnText test4(window);
    test4.setText("146");
    test4.setFont(fonts[1]);
    test4.setFontSize(20);
    test4.setColor(sf::Color(0, 0, 0, 255));
    //test.setPosition("XCENTER");
    test4.setPositionY(288.0f);
    test4.setPositionX(130.0f);
    test4.draw();

    // Disegna il player
    player.draw(window);

    window.display();
}


