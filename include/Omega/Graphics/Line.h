#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Math/MathFunctions.h"
#include "StaticValues.h"

namespace O {
namespace graphics {
	class Line
	{
	public:
		Line();
		Line(sf::RenderWindow* window, sf::Vector2f p1, sf::Vector2f p2, float width, float posRx = -1, float posRy = -1);
		Line(sf::RenderWindow* window, sf::Vector2f p, float angle, float length, float width, float posRx = -1, float posRy = -1);
		
		void event(sf::Event& e);

		///////////////////////////////////////////////////////////////:
		// update: dplace la texture en fonction du redimentionnement
		// de la fenetre
		// attention il faut appeler update apr�s les modification 
		// sur le sprite obligatoirement !
		void update();

		///////////////////////////////////////////////////////////////
		// mise a l'echelle en fonction de la taille de la fenetre
		// (sert pour les graphiques)
		void updateScale();


		///////////////////////////////////////////////////////////////:
		//affichage dans le fenetre
		void draw();


		///////////////////////////////////////////////////////////////:
		//gR = get rectangle shape
		// permet de modifier le sprite depuis l'exterieur
		// ex: sf::RectangleShape.gR().setPosition(.., ..);
		sf::RectangleShape& gR();

		///////////////////////////////////////////////////////////////:
		// setPosition qui prend en compte les facteurs de redimention
		void setPosition(float x, float y);
		void setPosition(float x, float y, bool update);
		void move(float x, float y);
		void setSize(float length, float width);
		void setPoints(sf::Vector2f p1, sf::Vector2f p2);
		void setPoints(sf::Vector2f p, float angle, float length);
		void setFillColor(sf::Color c);
		void setWidth(float w);
		sf::Color getFilleColor();
		sf::Vector2f getSize();
		float getWidth();
		sf::Vector2f getPosition();

		///////////////////////////////////////////////////////////////:
		// changer le point de redientionement
		void setPointRedi(float x, float y);

	private:

		void setPointsForScale(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f scale);

		///////////////////////////////////////////////////////////////
		// fenetre li�e � l'objet
		sf::RenderWindow* m_fen;

		///////////////////////////////////////////////////////////////:
		//rectangle
		sf::RectangleShape m_rectangle;

		///////////////////////////////////////////////////////////////:
		// point de redimention
		float m_posRx;
		float m_posRy;


		///////////////////////////////////////////////////////////////
		// points des extrem de la ligne
		sf::Vector2f m_p1;
		sf::Vector2f m_p2;
		float m_width;
		float m_length;
	};
}}