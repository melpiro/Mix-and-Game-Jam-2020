#include "Graphics/Button.h"


namespace O {
namespace graphics {
	Button::Button()
	{
		graphics::Text::setOrigineAsCenter();
	}




	Button::Button(sf::RenderWindow* window, std::string font, float x, float y, float sizeX, float sizeY, float posRx, float posRy, bool centered):
		m_fen(window),
		Rectangle(window, x, y, sizeX, sizeY, posRx, posRy, centered),
		Text(window,font, x, y, 0, 0, true) // le texte est toujour en centered !
	{
		m_baseColor = sf::Color::Transparent;
		m_hoverColor = sf::Color(255,255,255,150);
		m_outlineBaseColor = sf::Color::White;
		m_outlinehoverColor = sf::Color::White;
		setOutlineThickness(1);
		
		updatePosText();

	}

	Button::Button(sf::RenderWindow* window, std::string font, float x, float y, float sizeX, float sizeY, bool centered):
		Button(window, font,x,y,sizeX,sizeY,0,0,centered)
	{
	
	}

	bool Button::hover()
	{
		return Rectangle::hover();
	}

	bool Button::clicked(sf::Event& e)
	{
		if (hover())
		{
			if (e.type == sf::Event::MouseButtonReleased)
			{
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					return true;
				}
			}
		}

		return false;
	}

	void Button::setOutlineThickness(float v)
	{
		Rectangle::setOutlineThickness(v);
		updatePosText();
	}

	
	void Button::event(sf::Event e)
	{
		if (e.type == sf::Event::Resized)
		{
			Button::update();
		}
	}
	

	void Button::update()
	{
		
		Rectangle::update();
		updatePosText();
	}



	void Button::draw()
	{
		Rectangle::draw();
		Text::draw();
	}

	void Button::setPosition(float x, float y)
	{
		Rectangle::setPosition(x, y);
		updatePosText();

	}

	void Button::move(float x, float y)
	{
		Button::setPosition(Rectangle::getPosition().x + x, Rectangle::getPosition().y + y);
	}

	void Button::setPointRedi(float x, float y)
	{
		Rectangle::m_posRx = x;
		Rectangle::m_posRy = y;
		Text::m_posRx = x;
		Text::m_posRy = y;
	}

	void Button::setOrigineAsCenter()
	{
		Rectangle::setOrigineAsCenter();
		update();
	}
	void Button::updatePosText()
	{
		sf::FloatRect rect = m_rectangle.getGlobalBounds();
		Text::setPosition(rect.left + rect.width / 2.0, rect.top + rect.height / 2.0);
		Text::update();
	}
	void Button::setTextColor(sf::Color c)
	{
		m_text.setFillColor(c);
	}
}}