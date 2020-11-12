#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace O {
namespace graphics {

class DotGraphApp
{

public:

	DotGraphApp();

	void setPosition(int x, int y);

	void run();

	void close();

	void addDotGroup(std::string name, sf::Color couleur);
	void addDot(std::string name, sf::Vector2f coord);

	void setDotsRadius(double radius);

	void clear();

private:
	void event();
	void update();
	void render();

	// l'ajout se fait dans un tampon updateAdd va donc prendre les �l�ment du tampon et les mettre dans la vraie liste
	void updateAdd(std::string name, sf::Vector2f coord);
	void updateAdd();

	// update de l'affichage
	void updateView();

	sf::RenderWindow m_fen;

	double WIDTH_DOTS = 4.5;

	std::map<std::string, std::pair<std::pair<std::vector<sf::Vector2f>, std::vector<sf::CircleShape>>, sf::Color>> m_allDots;

	std::vector< std::pair<std::string, sf::Vector2f >> m_tempData;



};

}}