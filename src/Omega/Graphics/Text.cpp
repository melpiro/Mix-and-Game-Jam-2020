#include "Graphics/Text.h"


namespace O{
namespace graphics {

	Text::Text() : m_text()
	{
		m_x = 0;
		m_y = 0;
		m_isOrigineAsCenter = false;
	}
	Text::Text(sf::RenderWindow* window, std::string fontName, float x, float y, float posRx, float posRy, bool centered):
		m_fen(window),
		m_fontName(fontName),
		m_x(x), m_y(y), m_posRx(posRx), m_posRy(posRy)
	{
		if (centered)
		{
			// si l'objet doit etre centr�, un appel � update n'est pas n�c�saire
			// car la fonction setOrigineAsCenter le fait deja !
			setOrigineAsCenter();
		}
		else
		{
			update();
		}
	}

	Text::Text(sf::RenderWindow* window, std::string fontName, float x, float y, bool centered):
		Text(window, fontName, x, y, 0, 0, centered)
	{
		
	}

	void Text::loadFont()
	{
		m_text.setFont(ressourceManager.getFont(m_fontName));
		if (m_isOrigineAsCenter) setOrigineAsCenter();
		else
		{
			update();
		}
	}
	void Text::loadFont(sf::Font& f)
	{
		m_text.setFont(f);
		if (m_isOrigineAsCenter) setOrigineAsCenter();
		else
		{
			update();
		}
	}

	void Text::event(sf::Event e)
	{
		if (e.type == sf::Event::Resized)
		{
			update();
		}	
	}
	
	void Text::update()
	{
		//facteur de redimentionnement
		float factorX = (float)m_fen->getSize().x / STATIC::SYS::WIDTH;
		float factorY = (float)m_fen->getSize().y / STATIC::SYS::HIGHT;

		m_text.setPosition(m_x + (factorX - 1) * m_posRx, m_y + (factorY - 1) * m_posRy);
	}
	// void Text::update(float viewZoom)
	// {
	// 	setScale(viewZoom, viewZoom);

	// 	//facteur de redimentionnement
	// 	float factorX = (float)m_fen->getSize().x / STATIC::SYS::WIDTH;
	// 	float factorY = (float)m_fen->getSize().y / STATIC::SYS::HIGHT;

	// 	m_text.setPosition(m_x + (factorX - 1) * m_posRx * viewZoom, m_y + (factorY - 1) * m_posRy * viewZoom);
	// }

	void Text::draw()
	{
		m_fen->draw(m_text);
	}
	sf::Text& Text::gT()
	{
		return m_text;
	}
	void Text::setPosition(float x, float y)
	{
		m_x = x;
		m_y = y;
		update();
	}
	sf::Vector2f Text::getPosition()
	{
		return sf::Vector2f(m_x, m_y);
	}
	void Text::move(float x, float y)
	{
		setPosition(getPosition().x + x, getPosition().y + y);
	}
	bool Text::hover()
	{
		auto p = sf::Mouse::getPosition(*m_fen);
		return (m_text.getGlobalBounds().contains(p.x, p.y));
	}
	void Text::setScale(float x, float y)
	{
		m_text.setScale(x, y);
	}
	bool Text::clicked(sf::Event& e)
	{
		if (e.type == sf::Event::MouseButtonReleased)
		{
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				if (hover())
				{
					return true;
				}
			}
		}
		return false;
	}
	void Text::setString(sf::String text)
	{
		m_text.setString(text);

		if (m_isOrigineAsCenter) setOrigineAsCenter();
	}
	
	void Text::setString(sf::String text, double maxWidth)
	{
		m_text.setString(ready_text(text, maxWidth, m_text.getCharacterSize(), *m_text.getFont()));

		if (m_isOrigineAsCenter) setOrigineAsCenter();
	}
	sf::String Text::getString()
	{
		return m_text.getString();
	}
	void Text::setCharacterSize(unsigned int value)
	{
		m_text.setCharacterSize(value);
		if (m_isOrigineAsCenter) setOrigineAsCenter();
	}
	void Text::setPointRedi(float x, float y)
	{
		m_posRx = x;
		m_posRy = y;

		update();
	}
	void Text::setOrigineAsCenter()
	{
		sf::FloatRect r = m_text.getGlobalBounds();
		m_text.setOrigin(r.width / 2.0, r.height / 2.0 +(float) m_text.getCharacterSize() /2.0);
		m_isOrigineAsCenter = true;

		update();
	}

	sf::String Text::ready_text(sf::String text, int width,const int& font_size, const sf::Font &font)
	{
		int s_width = 0;
		int last_word = 0;
		for(size_t i = 0; i < text.getSize(); i++)
		{
			
			if(s_width < width)
			{
				if (text[i] == '\n') s_width = 0, last_word = 0;
				else s_width += font.getGlyph(text[i], font_size, false).advance;

			}
			if(s_width >= width)
			{
				if (last_word == 0)
				{
					text.insert(i, '\n');
					last_word = i;
					s_width = 0;
				}
				else
				{
					text.replace(last_word, 1, "\n");
					i = last_word;
					last_word = 0;
					s_width = 0;
				}
			}


			if(text[i] == ' ')
				last_word = i;
		}
		
		return text;
	}
}}