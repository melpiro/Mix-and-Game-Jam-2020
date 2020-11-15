//
// Created by etien on 15/11/2020.
//

#include <iostream>
#include "MusicManager.h"

std::map<std::string, sf::Music> MusicManager::musics;
std::map<std::string, float> MusicManager::targetVolume;

void MusicManager::init() {

    addMusic("explore", "resources/Musics/Tetradventure_Theme_-_by_Nova_Stral.ogg");
    addMusic("fight", "resources/Musics/Tetradventure_fight_-_by_Nova_Stral.ogg");

}

void MusicManager::addMusic(const std::string& name, const std::string& path) {
    if(!musics[name].openFromFile(path)) {
        std::cerr << "Music \"" << path << "\" not found" << std::endl;
    }
}

sf::Music *MusicManager::getMusic(const std::string& name) {
    return &musics[name];
}

void MusicManager::fadeTo(const std::string &name, int volume) {
    targetVolume[name] = volume;
}

