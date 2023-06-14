#ifndef FONTLOADER_HPP
#define FONTLOADER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class FontLoader
{
public:
    static void loadFontsFromDirectory(const std::string& directoryPath);
    static const std::vector<sf::Font>& getFonts();

private:
    static std::vector<sf::Font> fonts;
};

#endif // FONTLOADER_HPP
