//
// Created by Alarm on 14/11/2020.
//

#include <Spawner.h>
#include <LifePack.h>
#include "ObjectManager.h"

Tilemap* ObjectManager::m_tileMap;
PlayerCharacter* ObjectManager::m_hero;
std::map<int,Object*> ObjectManager::m_objets;
int ObjectManager::m_nextId;
sf::RenderWindow* ObjectManager::m_fen;
std::vector<int> ObjectManager::m_objToDel;

void ObjectManager::init() {
    m_nextId = 0;
}

void ObjectManager::addObject(Object *obj) {
    int id = assignId();
    obj->addId(id);
    m_objets.insert(std::pair<int,Object*>(id,obj));
}

void ObjectManager::delObject(int id) {
    m_objToDel.push_back(id);
}

void ObjectManager::loadObjectsFromFile(std::string path) {
    JsonData json;
    json.readFile(path);

    auto data = (std::vector<JsonData>*)json["Objects"].getValue();
    for(auto obj : *data){
        sf::String type = *((sf::String *)obj["type"].getValue());
        double x = *((double *)obj["x"].getValue());
        double y = *((double *)obj["y"].getValue());

        Object* o;
        if(type == "spawner"){
            sf::String typeMob = *((sf::String *)obj["typeMob"].getValue());
            double delay = *((double *)obj["spawnDelay"].getValue());
            o = new Spawner(O::str::convert_SFML_string_to_UTF8_string(typeMob),delay,sf::Vector2f(x,y),m_tileMap,m_hero,m_fen);
        }else if(type == "lifepack"){
            double lifeAmount = *((double *)obj["lifeAmount"].getValue());
            o = new LifePack(lifeAmount,sf::Vector2f(x,y),m_fen,m_hero);
        }//switch pour les items

        o->init();
        o->setPosition({static_cast<float>(x), static_cast<float>(y)});
        o->setFen(m_fen);
        addObject(o);

    }

}

void ObjectManager::draw() {
    for(auto p : m_objets){
        p.second->draw();
    }
}

void ObjectManager::update(float deltatime) {
    for(auto p : m_objets){
        p.second->update(deltatime);
    }
    for(auto id : m_objToDel){
        delete m_objets[id];
        m_objets.erase(id);
    }
    m_objToDel.clear();
}

void ObjectManager::event(sf::Event &e) {
    for(auto p : m_objets){
        p.second->event(e);
    }
}

void ObjectManager::setTileMap(Tilemap *tm) {
    m_tileMap = tm;
}

int ObjectManager::assignId() {
    for(int i = 0 ; i < m_nextId ; i++){
        if(m_objets.find(i) == m_objets.end()) return i;
    }
    return m_nextId++;
}

void ObjectManager::setFen(sf::RenderWindow *f) {
    m_fen = f;
}

void ObjectManager::setHero(PlayerCharacter *p) {
    m_hero = p;
}
