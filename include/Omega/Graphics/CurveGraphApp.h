#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Math/MathFunctions.h"
namespace O {
namespace graphics {
class CurveGraphApp
{

public:

	CurveGraphApp();

	void setPosition(int x, int y);
	
	void run();

	void close();

	void addCourbe(std::string name, sf::Color couleur);
	void addCourbe(std::string name, sf::Color couleur, double(*function)(double), double min, double max, double increment);
	void addPoint(std::string name,sf::Vector2f coord);

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

	double WIDTH_LINE = 5;

	std::map<std::string,std::pair<std::pair<std::vector<sf::Vector2f>,std::vector<sf::RectangleShape>>, sf::Color>> m_allCourbe;

	std::vector< std::pair<std::string, sf::Vector2f >> m_tempData;
	

	 
};
}}

