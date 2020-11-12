#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace O {
namespace graphics {
class BarsGraphApp
{

public:

	BarsGraphApp();

	void setPosition(int x, int y);

	void run();

	void close();

	void addBarreGroup(std::string name);
	void addBarre(std::string name, double hight, sf::Color couleur);
	void setMaxWidthBars(double maxWidth);
	void setMaxSizeSpaceBetweenGroup(double size);

	void setSize(std::string name, double hight, int id = -1);

	void erase(std::string name);

	void clear();

private:
	void event();
	void update();
	void render();

	// l'ajout se fait dans un tampon updateAdd va donc prendre les �l�ment du tampon et les mettre dans la vraie liste
	void updateAdd(std::string name, double hight, sf::Color c);
	void updateAdd();

	// update de l'affichage
	void updateView();

	sf::RenderWindow m_fen;

	double m_maxWidth = 30.0;
	double m_littleSpace = 5.0;
	double m_largeSpace = 15.0;

	std::map<std::string, std::vector<std::pair<std::pair<double, sf::RectangleShape>, sf::Color>>> m_allBars;


	std::vector< std::pair<std::string, std::pair<double, sf::Color> >> m_tempData;
	std::vector< std::string > m_tempErase;
	std::vector< std::pair< std::pair < std::string, int>, double>> m_tempResize;


};
}}
