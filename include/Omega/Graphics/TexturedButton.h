#pragma once
#include "Graphics/Sprite.h"
#include "Graphics/Text.h"
#include <SFML/Graphics.hpp>

namespace O {
namespace graphics {
	class TexturedButton : public graphics::Sprite, public graphics::Text
	{
	public:
		TexturedButton();
		TexturedButton(sf::RenderWindow* fen, std::string textureName, std::string fontName, float x = 0, float y = 0, float posRx = 0, float posRy = 0, bool centered = false);
		TexturedButton(sf::RenderWindow* fen, std::string textureName, std::string fontName, float x, float y, bool centered);

		///////////////////////////////////////////////////////////////:
		// d�finition des rectangles de modifications lors du hover
		void setRectButton(sf::IntRect rectB, sf::IntRect rectHover);

		void event(sf::Event e);

		///////////////////////////////////////////////////////////////:
		// updates
		void update();


		///////////////////////////////////////////////////////////////:
		// detection du passage de la souris sur le bouton
		// pour detecter un clic il faut le coupler � sf::event
		bool hover();

		///////////////////////////////////////////////////////////////:
		// d�t�ction du clic
		bool clicked(sf::Event &e);


		///////////////////////////////////////////////////////////////:
		// chargement des textures
		void loadRessources();
		void loadRessources(sf::Texture &tex);
		void loadRessources(sf::Font &font);
		void loadRessources(sf::Texture &tex, sf::Font &font);

		

		///////////////////////////////////////////////////////////////:
		// affichage
		void draw();


		///////////////////////////////////////////////////////////////:
		// set position button
		void setPosition(float x, float y);

		void move(float x, float y);

		///////////////////////////////////////////////////////////////:
		// changer le point de redientionement
		void setPointRedi(float x, float y);

		///////////////////////////////////////////////////////////////:
		// origine as center
		void setOrigineAsCenter();

		///////////////////////////////////////////////////////////////
		// update de la position du texte par apport a celle du rectangle
		void updatePosText();

		///////////////////////////////////////////////////////////////
		// couleur du text
		void setTextColor(sf::Color c);

		///////////////////////////////////////////////////////////////
		// automatique rect Hover
		void calcAutoRectHover();

		///////////////////////////////////////////////////////////////
		// calcule pour ne pas avoir de rect Hover
		void calcNoRectHover();

	protected:
		

		///////////////////////////////////////////////////////////////:
		// rect de modifications lors du hover ou non 
		sf::IntRect m_rectB;
		sf::IntRect m_rectHover;

	private:
		///////////////////////////////////////////////////////////////:
		// fenetre
		sf::RenderWindow* m_fen;

		
	};

}}
