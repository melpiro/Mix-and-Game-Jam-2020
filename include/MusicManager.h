//
// Created by etien on 15/11/2020.
//

#ifndef MIXGAMEJAM2020_MUSICMANAGER_H
#define MIXGAMEJAM2020_MUSICMANAGER_H

#include <thread>
#include <map>
#include <string>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>

class MusicManager {

    static std::map<std::string, sf::Music> musics;
    static std::map<std::string, float> targetVolume;

public:
    static void init();
    static void addMusic(const std::string& name, const std::string& path);
    static sf::Music* getMusic(const std::string& name);

    static void update(float dt) {


        for (auto& pair : targetVolume) {

            float vol = musics[pair.first].getVolume();

            if(vol == pair.second)
                continue;

            else if (vol < pair.second) {
                vol = std::min(100.f, vol + 100.f * dt);
            }

            else if (vol > pair.second) {
                vol = std::max(0.f, vol - 100.f * dt);
            }

            musics[pair.first].setVolume(vol);

        }

    }

    static void fadeTo(const std::string &name, int volume);
};


#endif //MIXGAMEJAM2020_MUSICMANAGER_H
