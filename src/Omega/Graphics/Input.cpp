#include "Graphics/Input.h"
namespace O{
namespace graphics {

	Input::Input()
	{

	}



	Input::Input(sf::RenderWindow* window, std::string font, float x, float y, float sizeX, float sizeY, float posRx, float posRy, bool centered):
		graphics::Button(window, font, x, y, sizeX, sizeY, posRx, posRy, centered)
	{
		graphics::Text::m_isOrigineAsCenter = false;
		graphics::Text::gT().setOrigin(0, 0);

		graphics::Button::setColorOnHover(sf::Color::Transparent, sf::Color::Transparent);
		graphics::Button::setOutlineColorOnHover(sf::Color::White, sf::Color::White);
		graphics::Button::setOutlineThickness(3);
		graphics::Button::setCharacterSize(sizeY - graphics::Button::getOutlineThickness() * 2.0 - 4);

		m_cursor.setSize(sf::Vector2f( 1, graphics::Button::gT().getCharacterSize() ));
		setCharacterSize(sizeY * 8.8 / 10.0);
		m_cursor.setFillColor(sf::Color::White);


		setFocus(false);
		update();

	}




	Input::Input(sf::RenderWindow* window, std::string font, float x, float y, float sizeX, float sizeY, bool centered):
		Input(window, font, x,y, sizeX, sizeY,0,0,centered)
	{

	}

	bool Input::event(sf::Event e)
	{
		if (e.type==sf::Event::Resized)
		{
			this->update();
		}
		if (Button::clicked(e))
		{
			m_haveFocus = true;
			updatePosCursor(sf::Vector2f(e.mouseButton.x,e.mouseButton.y));
		}
		else if (e.type == sf::Event::MouseButtonReleased)
		{
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				setFocus(false);
			}
		}
		else if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Left)
			{
				if (m_cusorIndex == -1)
				{
					if (m_text.getString().getSize() != 0)
					{
						m_cusorIndex = m_text.getString().getSize() - 1;
					}
				}
				else
				{
					m_cusorIndex --;
					if (m_cusorIndex<0) m_cusorIndex = 0;
				}
				updatePosCursor();
			}
			else if (e.key.code == sf::Keyboard::Right)
			{
				m_cusorIndex++;
				if (m_cusorIndex>m_text.getString().getSize()) m_cusorIndex = m_text.getString().getSize();

				updatePosCursor();
			}
		}

		if (m_haveFocus)
		{
			if (e.type == sf::Event::KeyReleased)
			{
				if (e.key.code == sf::Keyboard::Escape || e.key.code == sf::Keyboard::Return)
				{
					setFocus(false);
					return false;
				}
			}
			if (e.type == sf::Event::TextEntered)
			{
			    #ifdef __linux__
				if (e.text.unicode == 8)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
					{
						removeWord();
					}
					else removeChar();
				}
				else
				{
					addChar(e.text.unicode );
				}
				#endif // __linux__
				#ifdef __MINGW32__
				if (e.text.unicode == 8)
				{
					 removeChar();
				}
				else if (e.text.unicode == 127)
				{
					 removeWord();
				}
				else
				{
					addChar(e.text.unicode );
				}
				#endif // __MINGW32__
			}
		}
		return false;
	}

	void Input::setString(sf::String str)
	{
		graphics::Text::setString(str);
		update();
	}

	sf::String Input::getString()
	{
		return m_text.getString();
	}

	void Input::draw()
	{
		Button::draw();
		if (m_haveFocus)
		{
			m_fen->draw(m_cursor);
		}
	}

	void Input::setFocus(bool value)
	{
		if (value) m_cusorIndex = m_text.getString().getSize();
		m_haveFocus = value;
		update();
	}

	bool Input::haveFocus()
	{
		return m_haveFocus;
	}

	void Input::setPosition(float x, float y)
	{
		Rectangle::setPosition(x, y);
		updatePosText();
	}

	void Input::move(float x, float y)
	{
		setPosition(Rectangle::getPosition().x + x, Rectangle::getPosition().y + y);
	}

	void Input::update()
	{
		Rectangle::update();
		updatePosText();
		updatePosCursor();
	}

	void Input::setOutlineThickness(float v)
	{
		Rectangle::setOutlineThickness(v);
		updatePosText();
	}

	void Input::updatePosText()
	{
		if (m_haveFocus) updatePosCursor();
		sf::FloatRect rect = m_rectangle.getGlobalBounds();
		sf::FloatRect textRect = m_text.getGlobalBounds();
		Text::setPosition(rect.left + graphics::Button::gR().getOutlineThickness() + 2, rect.top + rect.height / 2.0 - ((double)m_text.getCharacterSize()) / 1.5 );
		Text::update();
	}

	void Input::updatePosCursor()
	{
		int nbLine = 0;
		for (size_t i = 0; i < m_cusorIndex; i++)
		{
			if (m_text.getString()[i] == '\n') nbLine++;
		}

		// todo compute the + 5.0
		if (m_text.getString().getSize() == 0)
		{
			m_cursor.setPosition(m_text.findCharacterPos(m_cusorIndex).x,
				m_text.getPosition().y + 5.0
			);
		}
		else if (m_cusorIndex > 0 && m_text.getString()[m_cusorIndex-1] == '\n')
		{
			m_cursor.setPosition(m_text.getPosition().x,
				m_text.getPosition().y + (nbLine) * (m_text.getFont()->getLineSpacing(m_text.getCharacterSize()))  + 5.0
			);
		}
		else if (m_cusorIndex == m_text.getString().getSize())
		{
			m_cursor.setPosition(m_text.findCharacterPos(m_cusorIndex - 1).x +  m_text.getFont()->getGlyph(m_text.getString()[m_cusorIndex - 1], m_text.getCharacterSize(), false).advance,
				m_text.getPosition().y + (nbLine) * (m_text.getFont()->getLineSpacing(m_text.getCharacterSize()))  + 5.0
			);
		}
		else
		{
			m_cursor.setPosition(m_text.findCharacterPos(m_cusorIndex).x,
				m_text.getPosition().y + (nbLine) * (m_text.getFont()->getLineSpacing(m_text.getCharacterSize()))  + 5.0
			);
		}
	}

	void Input::setTextColor(sf::Color c)
	{
		m_text.setFillColor(c);
		m_cursor.setFillColor(c);
	}

	void Input::setCharacterSize(int value)
	{
		Text::setCharacterSize(value);
		m_cursor.setSize(sf::Vector2f( 1, graphics::Button::gT().getCharacterSize() ));
	}

	void Input::addChar(sf::Uint32 c)
	{
		sf::String string = m_text.getString();

		if (c == 13) //retour a la ligne
		{
			// pad de retour a al aligne !
		}
		else
		{
			if (m_text.getGlobalBounds().width + m_text.getFont()->getGlyph(c, m_text.getCharacterSize(), false).advance < m_rectangle.getGlobalBounds().width - 8.0)
			{
				sf::String stringCpy = string;
				string.insert(m_cusorIndex,c);
				m_cusorIndex++;
			}
		}
		graphics::Button::setString(string);
		update();
	}


	void Input::removeChar()
	{
		sf::String string = m_text.getString();

		if (m_cusorIndex - 1 >= 0)
		{
			if (string.getSize() > 0)
			{
				string.erase(m_cusorIndex - 1);
				m_cusorIndex--;
				graphics::Button::setString(string);
			}
		}
		update();
	}

	void Input::removeWord()
	{
		sf::String string = m_text.getString();

		if (m_cusorIndex - 1 >= 0)
		{
			if (string.getSize() > 0)
			{
				while (m_cusorIndex - 1>=0 && (string[m_cusorIndex - 1] == ' '||string[m_cusorIndex - 1] == '\n'))
				{
					string.erase(m_cusorIndex - 1);
					m_cusorIndex--;
				}
				while (m_cusorIndex - 1>=0 && (string[m_cusorIndex - 1] != ' '&&string[m_cusorIndex - 1] != '\n'))
				{
					string.erase(m_cusorIndex - 1);
					m_cusorIndex--;
				}
				if (m_cusorIndex < string.getSize() && (string[m_cusorIndex] == ' '||string[m_cusorIndex] == ' '))
				{
					while (m_cusorIndex - 1>=0 && (string[m_cusorIndex - 1] == ' '||string[m_cusorIndex - 1] == '\n'))
					{
						string.erase(m_cusorIndex - 1);
						m_cusorIndex--;
					}
				}
				graphics::Button::setString(string);
			}
		}
		update();

	}

	void Input::updatePosCursor(sf::Vector2f clic)
	{
		// new computation
		sf::String text = m_text.getString();
		sf::Vector2f clicAbsolutePos = clic - m_text.getPosition();
		int index = text.getSize();
		bool find = false;
		double minDistance = 1000000000;
		for (size_t i = 0; i < text.getSize(); i++)
		{
			
			double d = clic.x - m_text.findCharacterPos(i).x;
			
			if (std::abs(d) < minDistance && std::abs(d) < m_text.getFont()->getGlyph(m_text.getString()[i], m_text.getCharacterSize(), false).advance)
			{
				minDistance = std::abs(d);
				index = i;
				find = true;
			}
		
		}
		m_cusorIndex = index;
		updatePosCursor();
	}


}
}