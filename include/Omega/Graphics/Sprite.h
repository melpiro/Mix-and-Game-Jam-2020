#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticValues.h"
#include "Graphics/RessourceManager.h"

namespace O {
namespace graphics {
	class Sprite
	{
	public:
		Sprite();
		Sprite(sf::RenderWindow* window, std::string textureName, float x = 0, float y = 0, float posRx = 0, float posRy = 0, bool centered = false);
		Sprite(sf::RenderWindow* window, std::string textureName, float x, float y, bool centered);

		void loadTexture();
		void loadTexture(sf::Texture& tex);

		
		void event(sf::Event e);

		///////////////////////////////////////////////////////////////:
		// update: dplace la texture en fonction du redimentionnement
		// de la fenetre
		// attention il faut appeler update apr�s les modification 
		// sur le sprite obligatoirement !
		void update();

		///////////////////////////////////////////////////////////////:
		//affichage dans le fenetre
		void draw();
		void draw(sf::FloatRect bound);


		///////////////////////////////////////////////////////////////:
		//gS = get sprit
		// permet de modifier le sprite depuis l'exterieur
		// ex: sf::sprite.gS().setPosition(.., ..);
		sf::Sprite& gS();


		///////////////////////////////////////////////////////////////:
		// setPosition qui prend en compte les facteurs de redimention
		void setPosition(float x, float y);
		void move(float x, float y);
		void setScale(float x, float y);
		sf::Vector2f getPosition();


		///////////////////////////////////////////////////////////////:
		// pour faire des bouttons
		bool hover();
		bool clicked(sf::Event e);


		///////////////////////////////////////////////////////////////:
		// changer le point de redientionement
		void setPointRedi(float x, float y);


		///////////////////////////////////////////////////////////////:
		// origine as center
		void setOrigineAsCenter();

		///////////////////////////////////////////////////////////////:
		// color
		void setColor(sf::Color c);

	protected:

		

		///////////////////////////////////////////////////////////////
		// fenetre li�e � l'objet
		sf::RenderWindow* m_fen;

		///////////////////////////////////////////////////////////////:
		//sprite
		sf::Sprite m_sprite;
		std::string m_textureName;

		///////////////////////////////////////////////////////////////:
		//position en x et y sans modification
		float m_x;
		float m_y;

		///////////////////////////////////////////////////////////////:
		// point de redimention
		float m_posRx;
		float m_posRy;

		///////////////////////////////////////////////////////////////:
		// origine as center
		bool m_isOrigineAsCenter;

	
	};
}}

