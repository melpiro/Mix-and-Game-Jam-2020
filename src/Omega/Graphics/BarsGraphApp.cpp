#include "Graphics/BarsGraphApp.h"

namespace O {
namespace graphics {

BarsGraphApp::BarsGraphApp()
{

}
void BarsGraphApp::setPosition(int x, int y)
{
	m_fen.setPosition(sf::Vector2i(x, y));
}
void BarsGraphApp::run()
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

void BarsGraphApp::event()
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

void BarsGraphApp::update()
{
	if (m_tempData.size() > 0 || m_tempErase.size() > 0 || m_tempResize.size() > 0) // si il y a un tampon
	{
		updateAdd();
	}
}

void BarsGraphApp::render()
{
	m_fen.clear(sf::Color(19, 19, 19));

	std::map<std::string, std::vector<std::pair<std::pair<double, sf::RectangleShape>, sf::Color>>>::iterator it;

	for (it = m_allBars.begin(); it != m_allBars.end(); it++)
	{
		for (size_t i = 0; i < it->second.size(); i++)
		{
			m_fen.draw(it->second[i].first.second);
		}
	}


	m_fen.display();
}

void BarsGraphApp::close()
{
	m_fen.close();
}


void BarsGraphApp::addBarreGroup(std::string name)
{
	std::vector<std::pair<std::pair<double, sf::RectangleShape>, sf::Color>> barre(0);
	m_allBars[name] = barre;
}

void BarsGraphApp::addBarre(std::string name, double height, sf::Color couleur)
{
	m_tempData.push_back(std::make_pair(name, std::make_pair(height, couleur)));
}

void BarsGraphApp::setMaxWidthBars(double maxWidth)
{
	m_maxWidth = maxWidth;
}

void BarsGraphApp::setMaxSizeSpaceBetweenGroup(double size)
{
	m_largeSpace = size;
}

void BarsGraphApp::setSize(std::string name, double hight, int id)
{
	m_tempResize.push_back(std::make_pair(std::make_pair(name, id), hight));
}

void BarsGraphApp::erase(std::string name)
{
	m_tempErase.push_back(name);
}


void BarsGraphApp::updateView()
{
	double margin = 30;

	double maxHight = -100000;
	double nbBarres = 0;
	double nbGroupsBarres = 0;

	double maxSize = (float(m_fen.getSize().y)) - 2.0 * margin;

	std::map<std::string, std::vector<std::pair<std::pair<double, sf::RectangleShape>, sf::Color>>>::iterator it = m_allBars.begin();
	bool ok = false;
	for (it = m_allBars.begin(); it != m_allBars.end(); it++)
	{
		nbGroupsBarres++;
		ok = true;
		for (size_t i = 0; i < it->second.size(); i++)
		{
			nbBarres++;
			if (it->second[i].first.first > maxHight) maxHight = it->second[i].first.first;
		}
	}

	if (!ok)
	{
		
	}
	else
	{
		//                                        
		double totalWidthOfBars = nbBarres * m_maxWidth;
		double totalWidthOfLargesSpaces = m_largeSpace * (nbGroupsBarres - 1);
		double totalWidthOfLittleSpaces = m_littleSpace * (nbBarres - nbGroupsBarres);
		double totalWidth = totalWidthOfBars + totalWidthOfLargesSpaces + totalWidthOfLittleSpaces;

		double coef = 1.0;
		if (totalWidth > m_fen.getSize().x - margin * 2.0)
		{
			coef = (m_fen.getSize().x - margin * 2.0) / totalWidth;
		}
		double posX = margin;
		for (it = m_allBars.begin(); it != m_allBars.end(); it++)
		{
			//double lastPosX = posX;
			// pour chaques bares du groupe
			for (size_t i = 0; i < it->second.size(); i++)
			{
				sf::RectangleShape* rect = &(it->second[i].first.second);
				rect->setSize(sf::Vector2f(m_maxWidth * coef, maxSize * it->second[i].first.first / maxHight));
				rect->setFillColor(it->second[i].second);
				rect->setPosition(posX, m_fen.getSize().y - margin - rect->getSize().y);
				
				posX += m_maxWidth * coef;
				if (i != it->second.size() - 1)
				{
					posX += m_littleSpace * coef;
				}
			}

			//it->second.setPosition((posX + lastPosX) / 2.0, m_fen.getSize().y - margin / 2.0);
			//it->second.setCharacterSize(25.0 * coef);
			//it->second.second.update();


			posX += m_largeSpace * coef;

			
		}
	}
}

void BarsGraphApp::clear()
{
	m_allBars.clear();
	m_tempData.clear();
}


void BarsGraphApp::updateAdd()
{
	// updates des ajout dans le tampon
	for (size_t i = 0; i < m_tempData.size(); i++)
	{
		updateAdd(m_tempData[i].first, m_tempData[i].second.first, m_tempData[i].second.second);
	}
	m_tempData.clear();

	//updates des modifications
	for (size_t i = 0; i < m_tempResize.size(); i++)
	{
		auto it = m_allBars.find(m_tempResize[i].first.first);
		if (it != m_allBars.end() && (size_t) m_tempResize[i].first.second < it->second.size())
		{
			it->second[m_tempResize[i].first.second].first.first = m_tempResize[i].second;
		}
	}
	m_tempResize.clear();
	
	//updates des deletes
	for (size_t i = 0; i < m_tempErase.size(); i++)
	{
		auto it = m_allBars.find(m_tempErase[i]);
		if (it != m_allBars.end())
			m_allBars.erase(it);
	}

	m_tempErase.clear();

	updateView();
}

void BarsGraphApp::updateAdd(std::string name, double height, sf::Color c)
{
	std::map<std::string, std::vector<std::pair<std::pair<double, sf::RectangleShape>, sf::Color>>>::iterator it = m_allBars.find(name);

	if (it != m_allBars.end())
	{
		sf::RectangleShape rect;
		it->second.push_back(std::make_pair(std::make_pair(height, rect), c));

			
	}
}

}}
