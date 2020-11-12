#pragma once

#include "Graphics/Button.h"
#include <bitset>

namespace O {
namespace graphics {
	class Input : public graphics::Button
	{
	public:
		Input();
		Input(sf::RenderWindow* window, std::string font, float x, float y, float sizeX, float sizeY, float posRx, float posRy, bool centered = false);
		Input(sf::RenderWindow* window, std::string font, float x, float y, float sizeX, float sizeY, bool centered = false);

		bool event(sf::Event e);

		void setString(sf::String str);
		sf::String getString();

		void draw();

		void setFocus(bool value);
		bool haveFocus();

		void setPosition(float x, float y);
		void move(float x, float y);
		void update();
		void setOutlineThickness(float v);

		void updatePosText();
		void updatePosCursor();

		///////////////////////////////////////////////////////////////
		// couleur du text
		void setTextColor(sf::Color c);

		void setCharacterSize(int value);

	protected:

		bool m_haveFocus;

		int m_cusorIndex = 0;

		sf::RectangleShape m_cursor;

		void updatePosCursor(sf::Vector2f clic);
		void addChar(sf::Uint32 c);
		void removeChar();
		void removeWord();

	};
}}
