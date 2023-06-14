#include <SFML/Audio.hpp>

class MusicPlayer
{
public:
    static MusicPlayer& getInstance()
    {
        static MusicPlayer instance;
        return instance;
    }

    void playMusic(const std::string& filename)
    {
        stopMusic(); // Ferma la musica corrente (se presente)
        if (music.openFromFile(filename))
        {
            music.setLoop(true); // Imposta la riproduzione in loop
            music.play();
        }
    }

    void stopMusic()
    {
        music.stop();
    }

private:
    MusicPlayer() {} // Costruttore privato per evitare l'istanziazione esterna
    MusicPlayer(const MusicPlayer&) = delete; // Disabilita il costruttore di copia
    MusicPlayer& operator=(const MusicPlayer&) = delete; // Disabilita l'operatore di assegnazione

    sf::Music music;
};
