#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticValues.h"
#include "Operators/PrintFunctions.h"

namespace O {
namespace graphics {
	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(sf::RenderWindow* window, float x, float y, float sizeX, float sizeY, float posRx, float posRy, bool centered = false);
		Rectangle(sf::RenderWindow* window, float x, float y, float sizeX, float sizeY, bool centered = false);

		///////////////////////////////////////////////////////////////:
		// update: dplace la texture en fonction du redimentionnement
		// de la fenetre
		// attention il faut appeler update apr�s les modification 
		// sur le sprite obligatoirement !
		void event(sf::Event& e);


		///////////////////////////////////////////////////////////////:
		//affichage dans le fenetre
		void draw();


		///////////////////////////////////////////////////////////////:
		//gS = get rectangle shape
		// permet de modifier le sprite depuis l'exterieur
		// ex: sf::RectangleShape.gR().setPosition(.., ..);
		sf::RectangleShape& gR();


		///////////////////////////////////////////////////////////////:
		// setPosition qui prend en compte les facteurs de redimention
		void setPosition(float x, float y);
		void setPosition(float x, float y, bool update);
		void move(float x, float y);
		void setScale(float x, float y);
		void setSize(float x, float y);
		void setSize(sf::Vector2f size);
		sf::Vector2f getSize();
		sf::Vector2f getPosition();

		void setFillColor(sf::Color c);
		void setOutlineColor(sf::Color c);
		void setFillColor(sf::Color c, bool noUpdateBaseColor);
		void setOutlineColor(sf::Color c, bool noUpdateOutlineBaseColor);
		void setOutlineThickness(float v);
		sf::Color getFillColor();
		sf::Color getOutlineColor();
		float getOutlineThickness();

		///////////////////////////////////////////////////////////////:
		// pour faire des bouttons
		bool hover();
		bool clicked(sf::Event& e);

		///////////////////////////////////////////////////////////////
		// update de la couleur en fonction du hover
		void setColorOnHover(sf::Color couleur);
		void setColorOnHover(sf::Color base, sf::Color hover);
		void setOutlineColorOnHover(sf::Color couleur);
		void setOutlineColorOnHover(sf::Color base, sf::Color hover);

		

		///////////////////////////////////////////////////////////////:
		// changer le point de redientionement
		void setPointRedi(float x, float y);

		///////////////////////////////////////////////////////////////:
		// r�cuperer le point de redientionement
		sf::Vector2f getPointRedi();


		///////////////////////////////////////////////////////////////:
		// origine as center
		void setOrigineAsCenter();

		
		void update();

	protected:

		

		///////////////////////////////////////////////////////////////
		// fenetre li�e � l'objet
		sf::RenderWindow* m_fen;


		///////////////////////////////////////////////////////////////:
		//rectangle
		sf::RectangleShape m_rectangle;


		///////////////////////////////////////////////////////////////:
		//position en x et y sans modification
		float m_x;
		float m_y;

		///////////////////////////////////////////////////////////////:
		// point de redimention
		float m_posRx;
		float m_posRy;

		///////////////////////////////////////////////////////////////
		// couleur pour le hover
		sf::Color m_baseColor;
		sf::Color m_hoverColor;
		sf::Color m_outlineBaseColor;
		sf::Color m_outlinehoverColor;

		///////////////////////////////////////////////////////////////:
		// origine as center
		bool m_isOrigineAsCenter;
	};
}}

