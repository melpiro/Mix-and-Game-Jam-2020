#include "Graphics/DotGraphApp.h"

namespace O{
namespace graphics{


DotGraphApp::DotGraphApp()
{

}
void DotGraphApp::setPosition(int x, int y)
{
	m_fen.setPosition(sf::Vector2i(x, y));
}
void DotGraphApp::run()
{
	m_fen.create(sf::VideoMode(800, 650), "graphique", sf::Style::Default, sf::ContextSettings(0, 0, 3));
	m_fen.setFramerateLimit(10);
	while (m_fen.isOpen())
	{
		event();
		update();
		render();
	}
}

void DotGraphApp::event()
{
	sf::Event e;
	while (m_fen.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			m_fen.close();
		}
	}
}

void DotGraphApp::update()
{
	if (m_tempData.size() > 0) // si il y a un tampon
	{
		updateAdd();
	}
}

void DotGraphApp::render()
{
	m_fen.clear(sf::Color(19, 19, 19));

	std::map<std::string, std::pair<std::pair<std::vector<sf::Vector2f>, std::vector<sf::CircleShape>>, sf::Color>>::iterator it;

	for (it = m_allDots.begin(); it != m_allDots.end(); it++)
	{
		for (size_t i = 0; i < it->second.first.second.size(); i++)
		{
			m_fen.draw(it->second.first.second[i]);
		}
	}

	m_fen.display();
}

void DotGraphApp::close()
{
	m_fen.close();
}


void DotGraphApp::addDotGroup(std::string name, sf::Color couleur)
{

	std::pair<std::pair<std::vector<sf::Vector2f>, std::vector<sf::CircleShape>>, sf::Color> dots;

	dots.first.first = std::vector < sf::Vector2f>(0);
	dots.first.second = std::vector < sf::CircleShape>(0);
	dots.second = couleur;

	m_allDots[name] = dots;

}

void DotGraphApp::addDot(std::string name, sf::Vector2f coord)
{
	m_tempData.push_back(std::make_pair(name, coord));
}

void DotGraphApp::setDotsRadius(double radius)
{
	WIDTH_DOTS = radius;
}

void DotGraphApp::updateView()
{
	double margin = 30;
	double maxX = -100000;
	double minX = 100000;
	double maxY = -100000;
	double minY = 100000;

	std::map<std::string, std::pair<std::pair<std::vector<sf::Vector2f>, std::vector<sf::CircleShape>>, sf::Color>>::iterator it = m_allDots.begin();
	bool ok = false;
	for (it = m_allDots.begin(); it != m_allDots.end(); it++)
	{
		if (it->second.first.first.size() >= 2)
		{
			ok = true;
			for (size_t i = 0; i < it->second.first.first.size(); i++)
			{
				if (it->second.first.first[i].x > maxX) maxX = it->second.first.first[i].x;
				if (it->second.first.first[i].x < minX) minX = it->second.first.first[i].x;
				if (it->second.first.first[i].y > maxY) maxY = it->second.first.first[i].y;
				if (it->second.first.first[i].y < minY) minY = it->second.first.first[i].y;
			}
		}

	}

	if (!ok)
	{
		maxX = 1;
		minX = 0;
		maxY = 1;
		minY = 0;
	}
	else
	{
		double sizeX = maxX - minX;
		double sizeY = maxY - minY;

		double dx = (800.0 - margin * 2.0) / sizeX;
		double dy = (650.0 - margin * 2.0) / sizeY;

		for (it = m_allDots.begin(); it != m_allDots.end(); it++)
		{
			for (size_t i = 0; i < it->second.first.second.size(); i++)
			{
				sf::Vector2f pos1((it->second.first.first[i].x - minX) * dx + margin, (it->second.first.first[i].y - minY) * dy + margin);
				sf::Vector2f pos2((it->second.first.first[i + 1].x - minX) * dx + margin, (it->second.first.first[i + 1].y - minY) * dy + margin);
				it->second.first.second[i].setPosition(pos1);
			}
		}
	}

}

void DotGraphApp::clear()
{
	m_allDots.clear();
	m_tempData.clear();
}


void DotGraphApp::updateAdd()
{
	for (size_t i = 0; i < m_tempData.size(); i++)
	{
		updateAdd(m_tempData[i].first, m_tempData[i].second);
	}
	m_tempData.clear();
	updateView();
}

void DotGraphApp::updateAdd(std::string name, sf::Vector2f coord)
{
	coord.y = -coord.y;
	std::map<std::string, std::pair<std::pair<std::vector<sf::Vector2f>, std::vector<sf::CircleShape>>, sf::Color>>::iterator it = m_allDots.find(name);

	if (it != m_allDots.end())
	{
		it->second.first.first.push_back(coord);
		if (it->second.first.first.size() >= 2)
		{
			sf::CircleShape circle(WIDTH_DOTS);
			circle.setOrigin(WIDTH_DOTS, WIDTH_DOTS);
			circle.setFillColor(it->second.second);

			it->second.first.second.push_back(circle);
		}
	}
}

}}