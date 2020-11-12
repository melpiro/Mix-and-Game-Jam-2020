#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>
#include <algorithm>
#include "Files/FileFunctions.h"
#include "String/EncodeFunction.h"

namespace O{
namespace graphics
{


class RessourceManager {

public:
    RessourceManager();

    void setDefaultTextureDir(const std::string& local);
    void addTexture(const std::string& local, const std::string& name);
    void addTextureAndLoadIt(const std::string& local, const std::string& name);
    void loadAllTextures();
    sf::Texture& getTexture(const std::string& name);


    void setDefaultAudioDir(const std::string& local);
    void addAudio(const std::string& local, const std::string& name);
    void loadAllAudio();
    sf::SoundBuffer& getAudio(const std::string& name);

    void setDefaultFontDir(const std::string& local);
    void addFont(const std::string& local, const std::string& name);
    void addFontAndLoadIt(const std::string& local, const std::string& name);
    void loadAllFont();
    sf::Font& getFont(const std::string& name);

    void loadAllRessources();

    RessourceManager(const int& c);

    void loadLanguage(const std::string& path);
    sf::String text(const int& line);


private:


    std::map<std::string,std::pair<std::string,sf::Texture>> m_allTextures;
    std::map<std::string,std::pair<std::string,sf::Font>> m_allFonts;
    std::map<std::string,std::pair<std::string,sf::SoundBuffer>> m_allSounds;

    std::string m_defaultTextureDir= ".";
    std::string m_defaultAudioDir= ".";
    std::string m_defaultFontDir= ".";

    std::vector<sf::String> m_texts;
};

extern RessourceManager ressourceManager;

}
}