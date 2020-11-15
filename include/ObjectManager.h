//
// Created by Alarm on 14/11/2020.
//

#ifndef MIXGAMEJAM2020_OBJECTMANAGER_H
#define MIXGAMEJAM2020_OBJECTMANAGER_H


#include "Object.h"
#include "Tilemap.h"
#include "PlayerCharacter.h"
#include "JsonData.hpp"



class ObjectManager {



public:


    static void addObject(Object* obj);
    static void delObject(int id);


    static void loadObjectsFromFile(std::string path);

    static void init();
    static void draw();
    static void update(float deltatime);
    static void event(sf::Event &e);
    static void reset();

    static void setTileMap(Tilemap* tm);
    static void setFen(sf::RenderWindow* f);
    static void setHero(PlayerCharacter* p);


private:

    static Tilemap* m_tileMap;
    static PlayerCharacter* m_hero;
    static std::map<int,Object*> m_objets;
    static std::vector<int> m_objToDel;
    static int m_nextId;
    static sf::RenderWindow* m_fen;

    static int assignId();

};


#endif //MIXGAMEJAM2020_OBJECTMANAGER_H
