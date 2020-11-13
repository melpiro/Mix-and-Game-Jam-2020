#include "RessourceManager.h"


namespace O{
namespace graphics
{


RessourceManager::RessourceManager() {
    std::cerr << "[O::Graphics::RessourceManager] Merci de ne pas instancier de ressources manager (utilisez la variable : O::Graphics::ressourceManager)\n";
}

RessourceManager::RessourceManager(const int& c) {
}




void RessourceManager::setDefaultTextureDir(const std::string& local)
{
    m_defaultTextureDir = local;
    if (m_defaultTextureDir.back() == '/') m_defaultTextureDir.pop_back();
}
void RessourceManager::addTexture(const std::string& local, const std::string& name)
{
    if (m_allTextures.find(name) == m_allTextures.end())
        m_allTextures[name] = std::make_pair(local, sf::Texture());
    else
    {
        std::cerr << "[O::Graphics::addTexture] une texture nomée : "<<name <<" est déja existante \n";
    }
    
}
void RessourceManager::addTextureAndLoadIt(const std::string& local, const std::string& name)
{
    if (m_allTextures.find(name) == m_allTextures.end())
    {
        sf::Texture tex;
        tex.loadFromFile(m_defaultTextureDir+"/"+local);
        m_allTextures[name] = std::make_pair(local, tex);
    }
    else
    {
        std::cerr << "[O::Graphics::addTextureAndLoadIt] une texture nomée : "<<name <<" est déja existante \n";
    }
}

void RessourceManager::loadAllTextures()
{
    
    for (auto it = m_allTextures.begin(); it != m_allTextures.end(); it++)
    {
        it->second.second.loadFromFile(m_defaultTextureDir+"/"+it->second.first);
    }
}
sf::Texture& RessourceManager::getTexture(const std::string& name)
{
    return m_allTextures[name].second;
}


void RessourceManager::setDefaultAudioDir(const std::string& local)
{
    m_defaultAudioDir = local;
}
void RessourceManager::addAudio(const std::string& local, const std::string& name)
{
    if (m_allSounds.find(name) == m_allSounds.end()) m_allSounds[name] = std::make_pair(local, sf::SoundBuffer());
    else std::cerr << "[O::Graphics::addAudio] un sons nomée : "<<name <<" est déja existante \n";
}
void RessourceManager::loadAllAudio()
{
    
    for (auto it = m_allSounds.begin(); it != m_allSounds.end(); it++)
    {
        it->second.second.loadFromFile(m_defaultAudioDir+"/"+it->second.first);
    }
}
sf::SoundBuffer& RessourceManager::getAudio(const std::string& name)
{
    return m_allSounds[name].second;
}

void RessourceManager::setDefaultFontDir(const std::string& local)
{
    m_defaultFontDir = local;
}
void RessourceManager::addFont(const std::string&  local, const std::string& name)
{
    if (m_allFonts.find(name) == m_allFonts.end()) m_allFonts[name] = std::make_pair(local, sf::Font());
    else std::cerr << "[O::Graphics::addFont] une police nomée : "<<name <<" est déja existante \n";
}
void RessourceManager::addFontAndLoadIt(const std::string& local, const std::string& name)
{
    if (m_allFonts.find(name) == m_allFonts.end())
    {
        sf::Font f;
        f.loadFromFile(m_defaultFontDir+"/"+local);
        m_allFonts[name] = std::make_pair(local, f);
    }
    else std::cerr << "[O::Graphics::addFontndLoadIt] une police nomée : "<<name <<" est déja existante \n";
}

void RessourceManager::loadAllFont()
{
    
    for (auto it = m_allFonts.begin(); it != m_allFonts.end(); it++)
    {
        it->second.second.loadFromFile(m_defaultFontDir+"/"+it->second.first);
    }
}
sf::Font& RessourceManager::getFont(const std::string& name)
{
    return m_allFonts[name].second;
}

void RessourceManager::loadAllRessources()
{
    loadAllAudio();
    loadAllFont();
    loadAllTextures();
}
void RessourceManager::loadLanguage(const std::string& path)
{
    m_texts = O::str::convert_UTF8_string_to_SFML_string(file::getAllLines(path));
}
sf::String RessourceManager::text(const int& line)
{
    return m_texts[line];
}


RessourceManager ressourceManager = RessourceManager(0);

}



}