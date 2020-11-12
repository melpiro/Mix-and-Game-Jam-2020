#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticValues.h"
#include "Graphics/RessourceManager.h"

namespace O {
namespace graphics {

	class Text
	{
	public:
		Text();
		Text(sf::RenderWindow* window, std::string fontName, float x = 0, float y = 0, float posRx = -1, float posRy = -1, bool centered = false);
		Text(sf::RenderWindow* window, std::string fontName, float x, float y, bool centered);


		void loadFont();
		void loadFont(sf::Font& f);

		///////////////////////////////////////////////////////////////:
		// update: dplace la texture en fonction du redimentionnement
		// de la fenetre
		// attention il faut appeler update apr�s les modification 
		// sur le sprite obligatoirement !
		void update();
		
		void event(sf::Event e);

		///////////////////////////////////////////////////////////////:
		//affichage dans le fenetre
		void draw();

		///////////////////////////////////////////////////////////////:
		//gS = get sprit
		// permet de modifier le sprite depuis l'exterieur
		// ex: sf::sprite.gS().setPosition(.., ..);
		sf::Text& gT();


		///////////////////////////////////////////////////////////////:
		// setPosition qui prend en compte les facteurs de redimention
		void setPosition(float x, float y);
		void move(float x, float y);
		sf::Vector2f getPosition();


		///////////////////////////////////////////////////////////////:
		//changer le texte 
		void setString(sf::String text);
		void setString(sf::String text, double maxWidth);
		sf::String getString();
		void setCharacterSize(unsigned int value);

		///////////////////////////////////////////////////////////////:
		// pour faire des bouttons
		bool hover();

		void setScale(float x, float y);

		///////////////////////////////////////////////////////////////
		// check du click sur le text
		bool clicked(sf::Event& e);

		///////////////////////////////////////////////////////////////:
		// changer le point de redientionement
		void setPointRedi(float x, float y);


		///////////////////////////////////////////////////////////////:
		// origine as center
		void setOrigineAsCenter();

		static sf::String ready_text(sf::String text, int width,const int& font_size, const sf::Font &font);

	protected:

		

		///////////////////////////////////////////////////////////////
		// fenetre li�e � l'objet
		sf::RenderWindow* m_fen;

		std::string m_fontName;

		///////////////////////////////////////////////////////////////:
		//texte
		sf::Text m_text;


		///////////////////////////////////////////////////////////////:
		//position en x et y sans modification
		float m_x;
		float m_y;

		///////////////////////////////////////////////////////////////:
		//position de d�calage de redimentions
		float m_posRx;
		float m_posRy;

		///////////////////////////////////////////////////////////////:
		// origine as center
		bool m_isOrigineAsCenter;
	};
}}


