#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticValues.h"
#include "Math/MathFunctions.h"

namespace O {
namespace graphics {
	class Circle
	{
	public:
		Circle();
		Circle(sf::RenderWindow* window, float x, float y, float radius, float posRx, float posRy, bool centered = false);
		Circle(sf::RenderWindow* window, float x, float y, float radius, bool centered = false);

		///////////////////////////////////////////////////////////////:
		// update: dplace la texture en fonction du redimentionnement
		// de la fenetre
		// attention il faut appeler update apr�s les modification 
		// sur le sprite obligatoirement !
		void event(sf::Event& e);


		void update();


		///////////////////////////////////////////////////////////////:
		//affichage dans le fenetre
		void draw();


		///////////////////////////////////////////////////////////////:
		//gC = get circle shape
		// permet de modifier le circle depuis l'exterieur
		// ex: sf::circle.gC().setscale(.., ..);
		sf::CircleShape& gC();


		///////////////////////////////////////////////////////////////:
		// setPosition qui prend en compte les facteurs de redimention
		void setPosition(float x, float y);
		void setPosition(float x, float y, bool update);
		void move(float x, float y);
		void setScale(float x, float y);
		void setRadius(float r);
		float getRadius();
		
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
		// origine as center
		void setOrigineAsCenter();

	protected:

		

		///////////////////////////////////////////////////////////////
		// fenetre li�e � l'objet
		sf::RenderWindow* m_fen;


		///////////////////////////////////////////////////////////////:
		//rectangle
		sf::CircleShape m_circle;


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

